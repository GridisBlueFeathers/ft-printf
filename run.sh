#!/bin/bash

make
cc -Wall -Werror -Wextra ./main.c ./libftprintf.a -I ./includes/ -o test && ./test
