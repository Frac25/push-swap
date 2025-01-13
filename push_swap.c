#include"push_swap.h"

int check_param(int argc, char **argv)
{
	int	i;
	int j;

	i = 1;
	while (i <= argc -1)
	{
		j = 0;
		if (argv[i][0] == '+' || argv[i][0] == '-')
			j++;
		if (argv[i][j] < '0' || argv[i][j] > '9')
			return(0);
		j++;
		while(argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return(1);
}

int	check_dup(list *l)
{
	int i;
	int j;
	int n;
	nod	*node_i;
	nod	*node_j;

	node_i = l->node_a;
	node_j = l->node_a;
	i = 0;
	n = 0;
	while (i < l->dim_a)
	{
		j = 0;
		while (j < l->dim_a)
		{
			if (node_i != node_j && node_i->value == node_j->value)
				n++;
			j++;
			node_j = node_j->next;
		}
		node_i = node_i->next;
		i++;
	}
	return (n);
}

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

	n = 0;
	if (argc <= 1)
		return(0);
	if(check_param(argc, argv) == 0)
		error();
	stack_a = init_stack(argv, argc - 1);
	if (stack_a == NULL)
		error();
	l = init_list(stack_a, argc - 1);
	if (l == NULL)
		error();
	if(check_dup(l) != 0)
		error();
	table = init_tab(l->node_a, (argc - 1));
	if (table == NULL)
		error();
//	printa(l);
	if (ever_sorted(l) == 1)
		return(0);
	if (argc == 4)
		n = sort_3(l);
	else
		n = sort(l, table);
	tester(l);
	printf("n = %d\n", n);
	return(1);
}

