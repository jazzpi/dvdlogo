/*  GIMP header image file format (RGB): /home/jasper/dev/dvdlogo/src/DVD_logo.h
 */

static unsigned int LOGO_width = 64;
static unsigned int LOGO_height = 33;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted
 */

#define HEADER_PIXEL(data, pixel)                                              \
  {                                                                            \
    pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4));                \
    pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2));        \
    pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33)));             \
    data += 4;                                                                 \
  }
static char* LOGO_header_data
    = "!!!!!!!!!!!!!!!!!!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!"
      "C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!"
      "C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!C!!!````````````````````````````````````````"
      "````````````````````````````````````````````````````C!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!C!!!````````````````````````````````````"
      "````````````````````````````C!!!C!!!C!!!C!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!C!!!````````````````````````````````````````"
      "````````````````````````````````````````````````````C!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!C!!!C!!!````````````````````````````````````"
      "````````````````````````````````````````C!!!C!!!C!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!C!!!````````````````````````````````````````"
      "````````````````````````````````````````````````````C!!!C!!!!!!!"
      "!!!!!!!!!!!!!!!!C!!!C!!!````````````````````````````````````````"
      "````````````````````````````````````````````````C!!!C!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!````````````"
      "````````````````````````````````````````````````````````C!!!!!!!"
      "!!!!!!!!!!!!C!!!C!!!````````````````````````````````````````C!!!"
      "C!!!C!!!C!!!````````````````````````````````````````C!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!"
      "C!!!````````````````````````````````````````````````````C!!!!!!!"
      "!!!!!!!!C!!!C!!!````````````````````````````````````````````C!!!"
      "C!!!C!!!C!!!C!!!C!!!C!!!C!!!````````````````````````C!!!C!!!!!!!"
      "!!!!!!!!!!!!!!!!C!!!````````````````````````C!!!!!!!!!!!!!!!!!!!"
      "C!!!C!!!````````````````````````````````````````````````C!!!C!!!"
      "!!!!!!!!C!!!````````````````````````````````````````````````````"
      "C!!!C!!!!!!!!!!!!!!!!!!!C!!!````````````````````````````C!!!!!!!"
      "!!!!!!!!!!!!!!!!C!!!````````````````````````C!!!!!!!!!!!!!!!!!!!"
      "!!!!C!!!````````````````````````````````````````````````````C!!!"
      "!!!!C!!!C!!!````````````````````C!!!C!!!````````````````````````"
      "C!!!!!!!!!!!!!!!!!!!!!!!C!!!C!!!````````````````````````C!!!!!!!"
      "!!!!!!!!!!!!C!!!C!!!````````````````````C!!!C!!!!!!!!!!!!!!!!!!!"
      "!!!!C!!!````````````````````````C!!!C!!!````````````````````C!!!"
      "C!!!C!!!````````````````````````C!!!C!!!````````````````````````"
      "C!!!!!!!!!!!!!!!!!!!!!!!!!!!C!!!````````````````````````C!!!!!!!"
      "!!!!!!!!!!!!C!!!````````````````````````C!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!C!!!````````````````````````C!!!C!!!````````````````````C!!!"
      "C!!!````````````````````````C!!!C!!!C!!!````````````````````````"
      "C!!!!!!!!!!!!!!!!!!!!!!!C!!!C!!!````````````````````````C!!!!!!!"
      "!!!!!!!!!!!!C!!!````````````````````````C!!!!!!!!!!!!!!!!!!!!!!!"
      "C!!!C!!!````````````````````````C!!!C!!!````````````````````````"
      "````````````````````````C!!!C!!!C!!!C!!!````````````````````C!!!"
      "C!!!!!!!!!!!!!!!!!!!C!!!C!!!````````````````````````C!!!C!!!!!!!"
      "!!!!!!!!!!!!C!!!````````````````````````C!!!!!!!!!!!!!!!C!!!C!!!"
      "C!!!````````````````````````C!!!C!!!C!!!C!!!````````````````````"
      "````````````````````C!!!C!!!!!!!C!!!````````````````````````C!!!"
      "!!!!!!!!!!!!C!!!C!!!C!!!````````````````````````C!!!C!!!!!!!!!!!"
      "!!!!!!!!C!!!C!!!````````````````````````C!!!C!!!C!!!C!!!C!!!````"
      "````````````````````````C!!!C!!!!!!!!!!!C!!!````````````````````"
      "````````````````C!!!C!!!!!!!!!!!C!!!````````````````````````C!!!"
      "C!!!C!!!C!!!C!!!````````````````````````````C!!!C!!!!!!!!!!!!!!!"
      "!!!!!!!!C!!!````````````````````````````````````````````````````"
      "````````````````````C!!!C!!!!!!!!!!!!!!!C!!!````````````````````"
      "````````````C!!!C!!!!!!!!!!!!!!!C!!!````````````````````````````"
      "````````````````````````````````````````C!!!C!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!C!!!````````````````````````````````````````````````````"
      "````````````C!!!C!!!C!!!!!!!!!!!!!!!!!!!C!!!C!!!````````````````"
      "````````C!!!C!!!!!!!!!!!!!!!C!!!C!!!````````````````````````````"
      "````````````````````````````````````C!!!C!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!C!!!````````````````````````````````````````````````````"
      "````C!!!C!!!C!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!C!!!````````````````"
      "````````C!!!!!!!!!!!!!!!!!!!C!!!````````````````````````````````"
      "````````````````````````C!!!C!!!C!!!C!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!C!!!````````````````````````````````C!!!C!!!C!!!C!!!C!!!"
      "C!!!C!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!C!!!````````````````"
      "````C!!!C!!!!!!!!!!!!!!!!!!!C!!!````````````````````````````````"
      "````C!!!C!!!C!!!C!!!C!!!C!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!C!!!C!!!````````````"
      "C!!!C!!!!!!!!!!!!!!!!!!!!!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!"
      "C!!!C!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!C!!!````````C!!!"
      "C!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!````````C!!!"
      "C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!"
      "C!!!C!!!C!!!C!!!````````````````````````````````````````````````"
      "````````````````````````````C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!"
      "C!!!C!!!C!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!C!!!C!!!C!!!C!!!C!!!C!!!````````````````````````````"
      "````````````````````````````````````````````````````````````````"
      "````````````````````````````````````````````````````````````````"
      "````````C!!!C!!!C!!!C!!!C!!!C!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!C!!!C!!!C!!!````````````````````````````````````````````````"
      "````````````````````````````````````````````````````````````````"
      "````````````````````````````````````````````````````````````````"
      "````````````````````````````C!!!C!!!C!!!C!!!!!!!!!!!!!!!!!!!!!!!"
      "C!!!C!!!````````````````````````````````````````````````````````"
      "````````````````````````````````C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!"
      "C!!!C!!!````````````````````````````````````````````````````````"
      "````````````````````````````````````````C!!!C!!!!!!!!!!!!!!!!!!!"
      "C!!!````````````````````````````````````````````````````````````"
      "````````````````````````````````C!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "C!!!C!!!````````````````````````````````````````````````````````"
      "````````````````````````````````````````````C!!!!!!!!!!!!!!!!!!!"
      "C!!!C!!!````````````````````````````````````````````````````````"
      "````````````````````````````````C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!"
      "C!!!````````````````````````````````````````````````````````````"
      "````````````````````````````````````C!!!C!!!C!!!!!!!!!!!!!!!!!!!"
      "!!!!C!!!C!!!C!!!C!!!````````````````````````````````````````````"
      "````````````````````````````````````````````````````````````````"
      "````````````````````````````````````````````````````````````````"
      "````````````````````````C!!!C!!!C!!!C!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!````````````````````"
      "````````````````````````````````````````````````````````````````"
      "````````````````````````````````````````````````````````````````"
      "C!!!C!!!C!!!C!!!C!!!C!!!C!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!C!!!C!!!C!!!C!!!C!!!C!!!"
      "C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!````````C!!!"
      "C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!C!!!"
      "C!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!C!!!C!!!C!!!C!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
      "";
