CC=gcc
WFLAGS=-g -Wall -Wextra -std=c99
CFLAG=-c
OFLAGS=-o
DIR_src=src/
DIR=bin/
SRC_c=$(wildcard $(DIR_src)*.c)
SRC_o=$(wildcard $(DIR)*.o)
EXE=monitor
FILES=Arquivos

all: binary exe

binary:
	mkdir -p $(DIR)
	$(CC) $(WFLAGS) $(CFLAG) $(SRC_c)
	mv *.o $(DIR)

exe:
	$(CC) $(WFLAGS) $(OFLAGS) $(EXE)  $(SRC_o)

clean:
	rm -rf $(DIR) $(EXE)

cleanArq:
	rm -rf $(FILES)
