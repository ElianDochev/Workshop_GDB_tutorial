NAME = test

SRC_ONE = example1.c
SRC_TWO = example2.c
SRC_THREE = example3.c

all: example1 example2 example3

example1: $(SRC_ONE)
	gcc -g3 -o $@ $^ -D EXAMPLE=1

example2: $(SRC_TWO)
	gcc -g3 -o $@ $^ -D EXAMPLE=2

example3: $(SRC_THREE)
	gcc -g3 -o $@ $^ -D EXAMPLE=3

clean:
	rm -f example1 example2 example3