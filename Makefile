NAME		=	push_swap

SRCS		=	main.c				\
				operations.c		\
				operations_extra.c	\
				utils.c				\
				algorithms.c		\
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
	# ./push_swap 8 5 6 4 3 2 17 7
	./push_swap 8 5 6 4 3 2 17 7 | wc -l

big: all
	# 100 numbers
	./push_swap 396 183 2595 1542 289 1713 316 2007 1401 3802 2401 1043 1891 3440 1599 64 2666 3421 537 3939 392 3104 695 2079 592 3267 2972 3314 1174 573 1997 3349 1307 3468 3889 1412 3704 3699 981 649 1200 684 156 2353 417 2156 3668 2947 2515 1049 3747 229 3363 3793 685 3001 1928 1787 3757 1731 46 668 356 3867 3312 2763 2965 1362 1091 2715 2957 1242 2731 1187 982 2498 3401 1074 15 2377 2638 2768 808 1127 790 1011 1804 1634 1039 3045 3563 2508 2292 1833 1696 3430 853 3484 1653 600

.PHONY: all clean fclean re
