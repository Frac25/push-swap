NAME = push_swap

PROG =	ft_printf\
		ft_printnb\
		instruction1\
		instruction2\
		instruction3\
		lib\
		liste\
		push_swap\
		rec_sort\
		split_pos\
		test\
		sort\

SRC = $(addsuffix .c, $(PROG))

OBJ = $(addsuffix .o, $(PROG))

CC = cc

CFLAGS = -Wall -Wextra -Werror

all :		$(NAME)

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

a :			$(all)
			$(clean)

.PHONY : 	all clean fclean re a
