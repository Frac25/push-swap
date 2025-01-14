#include"push_swap.h"

void error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int		n;
	list	*l;
	nod		*stack_a;
	tab		*table;

	if (argc <= 1)
		return(0);
	argv = check_param(argv, argc);
	argc = check_argc(argv);
	stack_a = init_stack(argv, argc);
	l = init_list(stack_a, argc);
	if (l == NULL)
	{
		free_all_node(stack_a);
		error();
	}
	table = init_tab(l->node_a, argc);
	if (table == NULL)
	{
		free_all_node(stack_a);
		free(l);
		error();
	}
	n = sort(l, table);
	tester(l);
	printf("n = %d\n", n);
	return(1);
}

