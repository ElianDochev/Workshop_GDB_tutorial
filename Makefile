NAME = test

SRC_BUGGY = buggy_program.c
SRC_FIXED = fixed_program.c

CC = gcc
CFLAGS = -lm

all: buggy

buggy: $(SRC_BUGGY)
	$(CC) $(CFLAGS) -o $(NAME)_buggy $(SRC_BUGGY)

fixed: $(SRC_FIXED)
	$(CC) $(CFLAGS) -o $(NAME)_fixed $(SRC_FIXED)

clean:
	rm -f $(NAME)_buggy $(NAME)_fixed

re: clean all

.PHONY: all clean re