CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRCS = push_swap.c check.c store_in_stack.c \
       list_modif.c disorder.c\
       strat_select.c write.c\
       rotate.c reverse_rotate.c swap.c push.c \
	   simple_alg.c medium_alg.c complex_alg.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c stacks.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
