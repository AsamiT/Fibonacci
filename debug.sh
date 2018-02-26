#!/bin/bash


for FILE in "$@"
do
    lldb "$FILE"
done