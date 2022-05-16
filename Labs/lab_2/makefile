#lab_2 makefile
CC = g++
SHELL = /bin/bash

vector_ops: thompsz_vector_ops.cpp
	$(CC) -c $^

stats: thompsz_stats.cpp
	$(CC) -c $^

pre_process: thompsz_pre_processing.cpp
	$(CC) -c $^

k_means.o: thompsz_k_means.cpp
	$(CC) -o run $^

all: pre_process vector_ops stats k_means.o
clean:
	rm *.o