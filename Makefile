NAME = push_swap

PROG =	ft_printf\
		ft_printnb\
		instruction\
		lib\
		liste\mak
		push_swap\
		rec_sort\
		split_pos\
		test\

SRC = $(addsuffix .c, $(PROG))

OBJ = $(addsuffix .o, $(PROG))

CC = cc

CFLAGS = -Wall -Wextra -Werror

all  :		$(NAME)

$(NAME) :	$(OBJ)
#			ar rcs $(NAME) $(OBJ)
			$(CC) $(OBJ) -o $(NAME)

%.o :		%.c
			$(CC) -c $< $(CFLAGS) -o $@

clean :
			rm -f $(OBJ)

fclean : 	clean
			rm -f $(NAME)

re : 		fclean all

.PHONY : 	all clean fclean re
