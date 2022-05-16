#!/bin/bash

# Author: Zach Thompson
# Date: 5/15/22
# Description: Reads gene name and returns its status for each time point

# read gene name
echo -p "Enter the gene to be queried: " gene

# find where the gene name is found in each time point and echo to screen the state of the gene for each time point
i=0
while [ $i -le 6 ]  #loop through all time pts
do
    if ($(grep -o $gene "expressed_$i.txt" | wc -l))
    then 
        echo "At time point $i: expressed"
    elif ($(grep -o $gene "stationary_$i.txt" | wc -l))
    then
        echo "At time point $i: stationary"
    elif
    then
        echo "At time point $i: suppressed"
    else
        echo "Could not find gene"
    fi
    (( i++ ))
done