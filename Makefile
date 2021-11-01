NAME		=	push_swap

SRCS		=	main.c			\
				operations.c	\
				utils.c			\
				init.c

HEADER		=	push_swap.h

OBJS		=	$(SRCS:.c=.o)

LIBFT		=	libft.a
LIBFTDIR	=	./libft/

CC			=	gcc
CFLAGS		=	-fsanitize=address -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C ./libft/
	$(CC) $(CFLAGS) $(LIBFTDIR)$(LIBFT) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -g -c -I . $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

push: all
	./push_swap 8 5 6 4 3 2 17 7

.PHONY: all clean fclean re
