#!/bin/bash

# Author: Zach Thompson
# Date: 5/15/22
# Description: Reads number of points to be processed and then calibrates that much data from all seven time points
#              Writes all output data to appropriately named files

#prompt user for input
read -p "Enter the number of microarray points to be processed: " num_points

# calibrate data
green_="./microarray/green_"
red_="./microarray/red_"
i=0

while [ $i -le 6 ]  # loop through the files
do   
    # process the files
    ./process "${red_}${i}.dat" "${red_}background_${i}.dat" "${green_}${i}.dat" "${green_}background_${i}.dat" "log_ratio_${i}.dat" $num_points
    # copy log ratio output data to new file
    cp log_ratio_$i.dat log_ratio_input.dat
    # run clustering program and write results to new file
    ./cluster "log_ratio_$i.dat"
    # copy the cluster output files to files who denote the corresponding time point 
    cp suppressed_genes.txt "suppressed_$i.txt"
    cp stationary_genes.txt "stationary_$i.txt"
    cp expressed_genes.txt "expressed_$i.txt"
    # write the  number of members in each cluster to a separate file for each time point
    touch summary.txt
    echo -n "Suppressed genes at time point $1: " >> summary.txt
    wc -l "suppressed_$i.txt" >> summary.txt
    echo -n "Stationary genes at time point $1: " >> summary.txt
    wc -l "stationary_$i.txt" >> summary.txt
    echo -n "expressed genes at time point $1: " >> summary.txt
    wc -l "expressed_$i.txt" >> summary.txt
    (( i++ ))
done

rm -f clusters_*