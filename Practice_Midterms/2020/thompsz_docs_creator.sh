#!/bin/bash

# Author: Zach Thompson
# Date: 3/8/2022
# Description: 2020 practice midterm attempt

# replace /* with another symbol to identify comments
# the /g at the end treats * as a wild card --> not sure what that actually means
sed '0,/\/\*/{s//start_comment/}' ./test_data/$1 > ./modded_data.txt
sed -i 's/\*\//end_comment/g' ./modded_data.txt

# remove comment boundary strings
# this sed takes all the lines between the two strings i gave it
sed -n '/start_comment/, /end_comment/p' ./modded_data.txt | sed 's/\*//' | sed 's/start_comment//' | sed 's/end_comment//' > output.txt

echo "====================================================================================================" >> output.txt

# the 0 says only look for the first instance of a match
# remove boundaries surrounding description to avoid repeats
sed -i '0,/start_comment/{s///}' ./modded_data.txt
sed -i '0,/end_comment/{s///}' ./modded_data.txt

# all instances of /* */ after are subsequent comment blocks for function definitions
sed -i 's/\/\*/start_comment/g' ./modded_data.txt
sed -n '/start_comment/, /end_comment/p' ./modded_data.txt | sed 's/\*//' | sed 's/start_comment//' | sed 's/end_comment//' | sed 's/\/\///' >> output.txt

# removes trailing white spaces
sed -i 's/^[ \t]*//;s/[ \t]*$//' output.txt