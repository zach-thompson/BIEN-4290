#!/bin/bash

# Author: Zach Thompson
# Date: 5/15/22
# Description: Reads number of points to be processed and then calibrates that much data from all seven time points
#              Writes all output data to appropriately named files

#prompt user for input
echo -p "Enter many microarray points should be processed: " num_points

# calibrate data
green_="./microarray/green_"
red_="./microarray/red_"
i=0

while [ $i -le 6 ]  # loop through all data files
do
    rm -f "clusters_${i}.txt"
    
    # preprocess the files
    ./process "${red_}${i}.dat" "${red_}background_${i}.dat" "${green_}${i}.dat" "${green_}background_${i}.dat" "log_ratio_${i}.dat" $num_points
    cp "log_ratio_${i}.dat" log_ratio_input.dat # copy log ratio output data to new file
    # run clustering program and write results to new file
    ./cluster "log_ratio_${i}.dat" >> "clusters_${i}.txt"
    # copy the cluster output files to files who denote the corresponding time point 
    cp expressed_gene.txt "expressed_${i}.txt"
    # write the cluster means and number of members in each cluster to a separate file for each time point
    wc -l "expressed_${i}.txt" >> "clusters_${i}.txt"
    cp suppressed_gene.txt "suppressed_${i}.txt"
    wc -l "suppressed_${i}.txt" >> "clusters_${i}.txt"
    cp stationary_gene.txt "stationary_${i}.txt"
    wc -l "stationary_${i}.txt" >> "clusters_${i}.txt"
    (( i++ ))
    
done

# Create summary file
cat clusters_* > summary.txt