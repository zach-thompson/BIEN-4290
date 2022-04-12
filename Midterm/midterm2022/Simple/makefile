# Zach's Midterm makefile

CC = g++ 
SHELL = /bin/bash

brennanb_corr.o: brennanb_corr.cpp
	$(CC) -o brennanb_corr.o $^

brennanb_stats.o: brennanb_stats.cpp
	$(CC) -c $^

all: brennanb_corr.o brennanb_stats.o 

clean:
	rm *.o
