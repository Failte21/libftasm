#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[1;37m'

gcc ft_cat.c -g libfts.a -o ft_cat

if [ -z "$1" ]
then
	echo "Usage: sh test_cat.sh [dirname]"
else
	FILES=$1/*
	for f in $FILES ; do
		echo "$WHITE"
		echo "$f"
		cat "$f" > cat.txt
		./ft_cat "$f" > ft_cat.txt
		DIFF=$(diff cat.txt ft_cat.txt) 
		if [ "$DIFF" != "" ] 
		then
			echo "$RED"
			echo $DIFF
			echo "KO"
		else
			echo "$GREEN"
			echo "OK"
		fi
	done
fi