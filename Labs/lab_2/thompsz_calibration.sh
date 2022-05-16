#!/bin/bash

# Author: Zach Thompson
# Date: 5/15/22
# Description: Reads number of points to be processed and then calibrates the requested data from all seven time points
# and writes output data to appropriately named files

#prompt user for input
read -p "Enter the number of microarray points to be processed: " num_points

# calibrate data
green_="./microarray/green_"
red_="./microarray/red_"
i=0

# make folder to hold output files
mkdir -p results

while [ $i -le 6 ]  # loop through the files
do   
    # process the files
    ./process "${red_}${i}.dat" "${red_}background_${i}.dat" "${green_}${i}.dat" "${green_}background_${i}.dat" "results/log_ratio_${i}.dat" $num_points
    
    # copy log ratio output data to new file
    touch results/log_ratio_input.dat
    cp results/log_ratio_$i.dat results/log_ratio_input.dat

    # run clustering program and write results to file
    ./cluster results/log_ratio_$i.dat

    # copy the cluster output files to files who denote the corresponding time point 
    cp suppressed_genes.txt "results/suppressed_$i.txt"
    cp stationary_genes.txt "results/stationary_$i.txt"
    cp expressed_genes.txt "results/expressed_$i.txt"

    # write the  number of members in each cluster to a separate file for each time point
    touch results/summary.txt
    echo -n "Suppressed genes at time point $i: " >> results/summary.txt
    wc -l < "results/suppressed_$i.txt" | tr -d "">> results/summary.txt
    echo -n "Stationary genes at time point $i: " >> results/summary.txt
    wc -l < "results/stationary_$i.txt" >> results/summary.txt
    echo -n "expressed genes at time point $i: " >> results/summary.txt
    wc -l < "results/expressed_$i.txt" >> results/summary.txt
    (( i++ ))
done