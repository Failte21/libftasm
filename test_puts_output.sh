#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[1;37m'

gcc ft_puts.c -g libfts.a -o ft_puts
gcc puts.c -g libfts.a -o puts

if [ -z "$1" ]
then
	echo "Usage: sh test_puts.sh [filename]"
else
	filename=$1
	while read line; do
	echo "$WHITE"
	echo $line
	./puts $line > expected.txt 
	./ft_puts $line > value.txt
	DIFF=$(diff expected.txt value.txt) 
	if [ "$DIFF" != "" ] 
	then
		echo "$RED"
		echo $DIFF
		echo "KO"
	else
		echo "$GREEN"
		echo "OK"
	fi
	done < $filename
fi

# rm -f expected.txt
# rm -f value.txt
