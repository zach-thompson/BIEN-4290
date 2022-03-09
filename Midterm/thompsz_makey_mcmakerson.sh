#! /bin/bash

# Author: Zach Thompson
# Date: 3/8/22
# Description: 2022 midterm attempt

# Make sure an argument was given
if [ ! $1 ]
then
    echo "Missing directory path"
    exit 1
fi

# Save directory path in variable for clarity
path=$1 # Use /midterm2022/Simple for testing

# Create makefile to write to
touch makefile
echo -e "# Zach's Midterm makefile\n\nCC = g++ \nSHELL = /bin/bash\n" > makefile

# Run through all files in directory to find file that includes "main("
# Save that file name under "executable"
cd $path
for FILE in *
do
    if (echo "$FILE" | grep -q ".cpp")
    then
        echo "$FILE: $FILE" | sed 's/.cpp/.o/' >> ~/BIEN-4290/Midterm/makefile
        
        if (grep -q "main(" $FILE)
        then
        executable=$(echo "$FILE" | sed 's/.cpp/.o/')  >> ~/BIEN-4290/Midterm/makefile
        echo -e "\t" '$(CC)' "-c" "$executable" '$@\n'  >> ~/BIEN-4290/Midterm/makefile
        else
        echo -e "\t"'$(CC)' " -o " '$@\n'  >> ~/BIEN-4290/Midterm/makefile
        fi
    fi

done

# Create "clean" target
cd ~/BIEN-4290/Midterm/
echo -e "\nclean:\n\trm *.o" >> makefile

# 1. Generate separate targets for each cpp file
# sample_corr.o:  brennanb_corr.cpp
#   $(CC) -o folder $^
# sample_stats.o: brennanb_stats.cpp
#   $(CC) -c $^

# 2. Generate an "all" target which consists of the above targets and generates and executable for the code
# all: sample_corr.o sample_stats.o

# 3. Generate a "clean" target that removes all relevant compilation files
# clean: rm *.o

# 4. Once you have generated the Makefile, perform a make all, then run the executable