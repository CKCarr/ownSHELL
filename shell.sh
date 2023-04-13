#!/bin/bash
while true
do
	echo -n "$ "  # print prompt
	read input  # read user input
	$input  # execute user input as a command
done
