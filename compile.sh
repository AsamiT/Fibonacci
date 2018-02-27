#!/bin/bash

FILE=Fibonacci
DATE=$(date)

if [ -f ./"$FILE" ]; then
    echo "Found old binary, deleting..."
    rm "$FILE"
fi
for VAL in "$@"
do
    echo "Compiling testcase $VAL..."
    echo "Compile time: $DATE" >> logfile
    gcc -o "$FILE" "$FILE".c testcase0"$VAL".c
done

