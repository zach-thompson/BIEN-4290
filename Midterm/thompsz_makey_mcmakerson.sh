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

# Create local makefile to write to
cd $1
touch makefile
echo -e "# Zach's Midterm makefile\n\nCC = g++ \nSHELL = /bin/bash\n" > makefile

# Run through all files in directory to find ones named *.cpp
# Run through .cpp files to find one that includes "main("
# Save that file name under "executable"
# Add file names to makefile with appropriate commands
for FILE in *
do
    if (echo "$FILE" | grep -q ".cpp")
    then
        echo "$FILE: $FILE" | sed 's/.cpp/.o/' >> makefile
        
        if (grep -q "main(" $FILE)
        then
        executable=$(echo "$FILE" | sed 's/.cpp/.o/')  >> makefile
        echo -e "\t"'$(CC)' "-o" "$executable" '$^\n'  >> makefile
        else
        echo -e "\t"'$(CC)' "-c" '$^\n'  >> makefile
        fi
    fi

done

# Create "all" target
targets=$(grep ":" makefile | cut -d ":" -f1 | tr '\n' ' ') # stores lines with ":" and cuts after it, converts newline to " "
echo "all: $targets" >> makefile

# Create "clean" target
echo -e "\nclean:\n\trm *.o" >> makefile