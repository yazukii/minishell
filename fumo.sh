#!/bin/bash
filename='fumo.txt'
n=1
while read line; do
echo "$line"
n=$((n+1))
if [ $n -lt 28 ]
then
	sleep .05
fi
done < $filename
