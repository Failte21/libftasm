#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[1;37m'

gcc test_cat.c -g libfts.a -o ft_cat

for d in * ; do
	echo "$WHITE"
	echo "$d"
    cat "$d" > cat.txt
	DIFF=$(diff cat.txt cat.txt) 
	if [ "$DIFF" != "" ] 
	then
		echo "$RED"
		echo "KO"
	else
		echo "$GREEN"
		echo "OK"
	fi
done