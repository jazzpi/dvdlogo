#include <assert.h>
#include <math.h>
#include <netdb.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <time.h>
#include <unistd.h>

#include "DVD_logo.h"
#include <bits/time.h>
#include <sys/socket.h>
#include <sys/types.h>

#define SPEED    2
#define NTHREADS 1

int connect_to(const char* addr, const char* port) {
  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;     // IPv4 or IPv6
  hints.ai_socktype = SOCK_STREAM; // TCP

  struct addrinfo* servinfo;

  int rv = getaddrinfo(addr, port, &hints, &servinfo);
  if (rv != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    exit(EXIT_FAILURE);
  }

  for (struct addrinfo* p = servinfo; p != NULL; p = p->ai_next) {
    int fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
    if (fd == -1) {
      continue;
    }

    if (connect(fd, p->ai_addr, p->ai_addrlen) == -1) {
      close(fd);
      continue;
    }

    freeaddrinfo(servinfo);
    return fd;
  }

  fprintf(stderr, "Failed to connect to %s:%s\n", addr, port);
  exit(EXIT_FAILURE);
}

char* recvline(int fd) {
  char* buf = malloc(1024);
  int i = 0;
  while (1) {
    int n = recv(fd, buf + i, 1, 0);
    if (n == 0) {
      fprintf(stderr, "Connection closed\n");
      exit(EXIT_FAILURE);
    }
    if (n == -1) {
      perror("recv");
      exit(EXIT_FAILURE);
    }
    if (buf[i] == '\n') {
      buf[i] = '\0';
      return buf;
    }
    i++;
  }
}

void HSVtoRGB(float h, float s, float v, int* r, int* g, int* b) {
  float c = v * s;
  float x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
  float m = v - c;
  float r1, g1, b1;
  if (h < 60) {
    r1 = c;
    g1 = x;
    b1 = 0;
  } else if (h < 120) {
    r1 = x;
    g1 = c;
    b1 = 0;
  } else if (h < 180) {
    r1 = 0;
    g1 = c;
    b1 = x;
  } else if (h < 240) {
    r1 = 0;
    g1 = x;
    b1 = c;
  } else if (h < 300) {
    r1 = x;
    g1 = 0;
    b1 = c;
  } else {
    r1 = c;
    g1 = 0;
    b1 = x;
  }
  *r = (int)((r1 + m) * 255.0 + 0.5);
  *g = (int)((g1 + m) * 255.0 + 0.5);
  *b = (int)((b1 + m) * 255.0 + 0.5);
}

typedef enum { SE, NE, SW, NW } dir_t;

static volatile unsigned canvas_width, canvas_height;
static volatile unsigned x_pos, y_pos;
int8_t volatile color[3];
static const char* host;
static const char* port;
static int* img;

void* child(void* arg) {
  unsigned* startrow = arg;
  char* buf = malloc(1024);

  int fd = connect_to(host, port);
  if (*startrow == 0) {
    assert(send(fd, "SIZE\n", 5, 0) == 5);
    char* line = recvline(fd);
    assert(sscanf(line, "SIZE %u %u\n", &canvas_width, &canvas_height) == 2);
    printf("%d x %d\n", canvas_width, canvas_height);
    free(line);
  } else {
    while (canvas_height == 0)
      ;
  }

  while (1) {
    for (unsigned row = *startrow; row < LOGO_height; row += NTHREADS) {
      for (unsigned col = 0; col < LOGO_width; col++) {
        unsigned x = x_pos + col;
        unsigned y = y_pos + row;
        int8_t px = img[row * LOGO_width + col];
        if (px == 0) {
          // Just let others clear the rest
          continue;
        }
        sprintf(buf, "PX %d %d %02hhx%02hhx%02hhx\n", x, y, color[0], color[1],
                color[2]);
        if (send(fd, buf, strlen(buf), 0) != (ssize_t)strlen(buf)) {
          perror("send");
          free(buf);
          while ((buf = recvline(fd)) != NULL) {
            fprintf(stderr, "Server message: %s\n", buf);
            free(buf);
          }
          free(img);
          close(fd);
          exit(EXIT_FAILURE);
        }
      }
    }
  }
}

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s ADDR PORT\n", argv[0]);
    return EX_USAGE;
  }
  host = argv[1];
  port = argv[2];

  img = malloc(sizeof(*img) * LOGO_width * LOGO_height);
  int px[3];
  for (unsigned row = 0; row < LOGO_height; row++) {
    for (unsigned col = 0; col < LOGO_width; col++) {
      HEADER_PIXEL(LOGO_header_data, px);
      if (px[0] == 0) {
        assert(px[1] == 0 && px[2] == 0);
      } else {
        assert(px[0] == 255 && px[1] == 255 && px[2] == 255);
      }
      img[row * LOGO_width + col]
          = ~px[0]; // for some reason, the image is inverted
    }
  }

  struct timespec last;
  clock_gettime(CLOCK_MONOTONIC_RAW, &last);
  x_pos = 0;
  y_pos = 0;
  dir_t dir = SE;
  double hue = 0;
  int colint[3];
  HSVtoRGB(hue, 1, 1, colint + 0, colint + 1, colint + 2);
  color[0] = colint[0];
  color[1] = colint[1];
  color[2] = colint[2];

  pthread_t threads[NTHREADS];
  unsigned rows[NTHREADS];
  for (size_t i = 0; i < NTHREADS; i++) {
    rows[i] = i;
    assert(pthread_create(&threads[i], NULL, child, &rows[i]) == 0);
    sleep(1);
  }
  while (1) {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC_RAW, &now);
    int delta = (now.tv_sec - last.tv_sec) * 1000
                + (now.tv_nsec - last.tv_nsec) / 1000000;
    if (delta > 20) {
      last = now;
      switch (dir) {
      case SE:
        x_pos += SPEED;
        y_pos += SPEED;
        break;
      case NE:
        x_pos += SPEED;
        y_pos -= SPEED;
        break;
      case SW:
        x_pos -= SPEED;
        y_pos += SPEED;
        break;
      case NW:
        x_pos -= SPEED;
        y_pos -= SPEED;
        break;
      }
      bool left = x_pos == 0;
      bool right = x_pos + LOGO_width >= canvas_width;
      bool top = y_pos == 0;
      bool bottom = y_pos + LOGO_height >= canvas_height;
      dir_t prev_dir = dir;
      switch (dir) {
      case SE:
        if (right && bottom) {
          dir = NW;
        } else if (right) {
          dir = SW;
        } else if (bottom) {
          dir = NE;
        }
        break;
      case NE:
        if (right && top) {
          dir = SW;
        } else if (right) {
          dir = NW;
        } else if (top) {
          dir = SE;
        }
        break;
      case SW:
        if (left && bottom) {
          dir = NE;
        } else if (left) {
          dir = SE;
        } else if (bottom) {
          dir = NW;
        }
        break;
      case NW:
        if (left && top) {
          dir = SE;
        } else if (left) {
          dir = NE;
        } else if (top) {
          dir = SW;
        }
        break;
      }
      if (dir != prev_dir) {
        hue = fmod(hue + 45, 360);
        printf("Hue: %f\n", hue);
        HSVtoRGB(hue, 1, 1, colint + 0, colint + 1, colint + 2);
        color[0] = colint[0];
        color[1] = colint[1];
        color[2] = colint[2];
      }
    }
  }
  free(img);

  return 0;
}
