CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = simple_alg.c medium_alg.c complex_alg.c /
	   list_modif.c rotates.c push_swaps.c /
	   push_swap

all: NAME

NAME = stack.a

OBJ = $(SRCS .c:=.o)

OBJ: SRCS stack.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm %.o

fclean: clean
	rm $(NAME)

re: fclean
	all

.PHONY: clean, fclean, all, re
