#lab_2 makefile
CC = g++
SHELL = /bin/bash

all: pre_process.o vector_ops.o stats.o k_means.o

vector_ops.o: thompsz_vector_ops.cpp
	$(CC) -c $^

stats.o: /../lab_1/thompsz_stats.cpp
	$(CC) -c $^

pre_process.o: thompsz_pre_processing.cpp
	$(CC) -c $^

k_means.o: thompsz_k_means.cpp thompsz_k_means_test.cpp
	$(CC) -c $^

clean:
	rm *.o