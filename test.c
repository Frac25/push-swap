#include<stdio.h>
#include<unistd.h>

//typedef struct s_list
//{
//	int		value;
//	int		index;
//	struct	s_list *next;
//} t_list;

typedef struct s_list
{
	int		value;
	int		index;
	char	*next;
} t_list;

int	main(void)
{
	t_list		stack_a;
	int i;

	i = 1;
	stack_a.value = 37;
	stack_a.index = 1;
	stack_a.next = NULL;

	printf("i = %d\n", i);
	printf("stack_a.value = %d\n", stack_a.value);
	return (0);
}
