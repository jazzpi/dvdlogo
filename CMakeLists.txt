cmake_minimum_required(VERSION 3.10)
project("DVD Logo Pixelflut" C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra -g) # -fsanitize=address)
add_compile_options(-O3 -march=native -mtune=native)

add_link_options(-lm) # -fsanitize=address)
add_executable(dvdlogo src/main.c)
