NAME = push_swap

PROG =	check\
		ft_printf\
		ft_printnb\
		ft_split2\
		instruction1\
		instruction2\
		instruction3\
		instruction4\
		instruction5\
		lib\
		liste\
		post_sort\
		push_swap\
		rec_sort\
		split_pos\
		sort\
		sort_pos\
		test\
		rec_sort_2\


SRC = $(addsuffix .c, $(PROG))

OBJ = $(addsuffix .o, $(PROG))

CC = cc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS =  -fsanitize=address

all :		$(NAME)

$(NAME) :	$(OBJ)
#			ar rcs $(NAME) $(OBJ)
			$(CC) $(OBJ) -o $(NAME)
#			$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o :		%.c
#			$(CC) -c $< $(CFLAGS) -o $@
			$(CC) $(CFLAGS) -c $< -o $@

clean :
			rm -f $(OBJ)

fclean : 	clean
			rm -f $(NAME)

re : 		fclean all

a :			all clean

.PHONY : 	all clean fclean re a
