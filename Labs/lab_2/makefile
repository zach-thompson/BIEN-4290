#lab_2 makefile
CC = g++
SHELL = /bin/bash

vector_ops: thompsz_vector_ops.cpp
	$(CC) -c $^

stats: thompsz_stats.cpp
	$(CC) -c $^

pre_process.o: thompsz_pre_processing.cpp thompsz_vector_ops.cpp
	$(CC) -o process $^

k_means.o: thompsz_k_means.cpp
	$(CC) -o cluster $^

all: pre_process.o vector_ops stats k_means.o
clean:
	rm *.o
	rm process
	rm cluster