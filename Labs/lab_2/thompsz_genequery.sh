#!/bin/bash

# Author: Zach Thompson
# Date: 5/15/22
# Description: Reads gene name and returns its status for each time point

# read gene name
read -p "Enter the gene to be queried: " gene

# locate the gene at each time point and output its status
i=0
while ($i -le 6)  # loop through the files
do
    if ($(grep -o $gene "suppressed_$i.txt" | wc -l))
    then
        echo "At time point $i: $gene was suppressed"
    elif ($(grep -o $gene "stationary_$i.txt" | wc -l))
    then
        echo "At time point $i: $gene was stationary"
    elif ($(grep -o $gene "expressed_$i.txt" | wc -l))
    then 
        echo "At time point $i: $gene was expressed"
    else
        echo "Could not find gene"
    fi
    ((i++))
done