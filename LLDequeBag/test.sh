#!/bin/bash

truncate -s 0 stuff.txt

for ((n=1000; n<256001; n=n*2));
do ./prog $n >> stuff.txt;
done

./main
