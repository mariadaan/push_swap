NAME_S		=	push_swap
NAME_B		=	checker

SRCS_S		=	src/main.c

SRCS_E		=	src/check_input.c		\
				src/operations.c		\
				src/operations_extra.c	\
				src/utils.c				\
				src/algorithms.c		\
				src/init.c

SRCS_B		=	bonus/checker.c

HEADER		=	push_swap.h

OBJS_S		=	$(SRCS_S:.c=.o) $(SRCS_E:.c=.o)
OBJS_B		=	$(SRCS_E:.c=.o) $(SRCS_B:.c=.o)

LIBFT		=	libft.a
LIBFTDIR	=	./libft/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

ifdef WITH_BONUS
OBJS = $(OBJS_B)
NAME = $(NAME_B)
else
OBJS = $(OBJS_S)
NAME = $(NAME_S)
endif

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C ./libft/
	$(CC) $(CFLAGS) $(LIBFTDIR)$(LIBFT) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c -I . $(CFLAGS) -c $< -o $@

bonus:
	rm -f $(SRCS_S:.c=.o)
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJS_S) $(OBJS_B)

fclean: clean
	rm -f $(NAME_S) $(NAME_B)

re: fclean all

push: all
	# ./push_swap 8 5 6 4 3 2 17 7
	./push_swap 8 5 6 4 3 2 17 7 | wc -l

big: all
	# 100 numbers
	./push_swap 396 183 2595 1542 289 1713 316 2007 1401 3802 2401 1043 1891 3440 1599 64 2666 3421 537 3939 392 3104 695 2079 592 3267 2972 3314 1174 573 1997 3349 1307 3468 3889 1412 3704 3699 981 649 1200 684 156 2353 417 2156 3668 2947 2515 1049 3747 229 3363 3793 685 3001 1928 1787 3757 1731 46 668 356 3867 3312 2763 2965 1362 1091 2715 2957 1242 2731 1187 982 2498 3401 1074 15 2377 2638 2768 808 1127 790 1011 1804 1634 1039 3045 3563 2508 2292 1833 1696 3430 853 3484 1653 600

.PHONY: all clean fclean re bonus
