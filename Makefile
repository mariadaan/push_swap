NAME		=	push_swap

SRCS		=	push.c

HEADER		=	

OBJS		=	$(SRCS:.c=.o)

LIBFT		=	libft.a
LIBFTDIR	=	./libft/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

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
