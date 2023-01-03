#!/bin/bash

echo "Enter any number"
read s

if [[ ( $s -eq 10 || $s -eq 40 ) ]]
then
	echo "Well Played"
else
	echo "Sorry, You Failed"
fi

