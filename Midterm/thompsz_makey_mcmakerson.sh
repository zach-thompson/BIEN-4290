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
echo -e "# Zach's midterm makefile\n\nCC = g++\nSHELL = /bin/bash\n" > makefile

# Run through all files in directory to find ones named *.cpp
# Run through .cpp files to find one that includes "main(", use -o
# Add file names to makefile with appropriate commands
for FILE in *
do
    if (grep -q "#include" "$FILE" && grep -q ".hpp" "$FILE") # identifies which files include headers
    then
        target=$(echo -n "$FILE" | sed 's/.cpp/.o/') # converts name from *.cpp to *.o
        included=$(grep ".hpp" $FILE | tr -d '#"' | sed 's/include //g' | tr '\n' ' ' | sed 's/.hpp/.o/g' | sed 's/'$target'//') # stores all included header files
    fi

    if (echo "$FILE" | grep -q ".cpp") # looks for .cpp files
    then        
        if (grep -q "main(" $FILE) # determines which .cpp contains a main function
        then
        echo -n "$FILE: $FILE " | sed 's/.cpp/.o/' >> makefile # prints target.o: target.cpp, no newline
        echo $included >> makefile # prints included targets
        executable=$(basename $1)
        echo -e "\t"'$(CC)' "-o" "$executable" '$^\n'  >> makefile # prints compile line with executable (name of folder)
        else
        echo "$FILE: $FILE $included" | sed 's/.cpp/.o/' >> makefile # prints target.o: target.cpp
        echo -e "\t"'$(CC)' "-c" '$^\n'  >> makefile # prints compile line
        fi
    fi

done

# Create "all" target including all .cpp targets
targets=$(grep ":" makefile | cut -d ":" -f1 | tr '\n' ' ') # stores lines with a colon and cuts after it, converts newline to " "
echo "all: $targets" >> makefile

# Create "clean" target
echo -e "\nclean:\n\trm *.o\n" >> makefile

# Once the makefile is ready, perform a make all and run the executable
make all
./$executable