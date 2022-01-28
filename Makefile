CC = gcc
OPTIONS = -Wall
EXE = cesar

all: link

build:
	$(CC) $(OPTIONS) -c *.c

link: build
	$(CC) *.o -o $(EXE)

start: all
	./$(EXE) entree.txt sortie.txt

.PHONY: clean

clean:
	rm -f $(EXE)
	rm -f *.o
	rm -f *.txt

test: all
	bats check.bats
