#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[1;37m'

echo '---------------- LSIMON MAIN --------------------'
gcc main.c -g libfts.a -o test_main
./test_main
rm -f test_main

echo '---------------- EKELEN MAIN --------------------'
gcc liz_main.c -g libfts.a -o liz_main
./liz_main
rm -f liz_main

echo '---------------- FT_CAT TEST --------------------'
sh test_cat.sh .

echo '---------------- FT_PUTS OUT --------------------'
sh test_puts_output.sh MAKEFILE