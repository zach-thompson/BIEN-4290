#lab_2 makefile
CC = g++
SHELL = /bin/bash

all: pre_process.o vector_ops.o stats.o

vector_ops.o: thompsz_vector_ops.cpp
	$(CC) -c $^

stats.o: thompsz_stats.cpp
	$(CC) -c $^

pre_process.o: thompsz_pre_processing.cpp
	$(CC) -c $^

clean:
	rm *.o