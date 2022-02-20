#lab_2 makefile
CC = g++
SHELL = /bin/bash

vector_ops.o: thompsz_vector_ops.cpp
	$(CC) -c $^

thompsz_stats.o: thompsz_stats.cpp thompsz_stats.hpp
	$(CC) -c $^

all: vector_ops.o thompsz_stats.o