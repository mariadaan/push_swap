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

.PHONY: all clean fclean re bonus
