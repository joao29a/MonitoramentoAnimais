CC=gcc
WFLAGS=-g -Wall -Wextra
CFLAG=-c
OFLAGS=-o
DIR=bin/
SRC_c=$(wildcard *.c)
SRC_o=$(wildcard $(DIR)*.o)
EXE=monitor

all: binary exe

binary:
	mkdir -p $(DIR)
	$(CC) $(WFLAGS) $(CFLAG) $(SRC_c)
	mv *o $(DIR)

exe:
	$(CC) $(WFLAGS) $(OFLAGS) $(EXE)  $(SRC_o)

clean:
	rm -rf $(DIR) $(EXE)
