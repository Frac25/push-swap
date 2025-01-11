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
	while (i < l->dim_a -1) // a verifier
	{
		j = 0;
		while (j < l->dim_a -1) //revoir dim_a pour supprimer le -1
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

void	discret(list *l)
{
	int j;
	int rank;
	nod	*node_i;
	nod	*node_j;

	node_i = l->node_a;
	node_j = l->node_a;
	while (node_i->discret == 0)
	{
		rank = 0;
		j = 0;
		while (j < l->dim_a -1) //revoir dim_a pour supprimer le -1
		{
			if (node_i->value >= node_j->value)
				rank++;
			j++;
			node_j = node_j->next;
		}
		node_i->discret = rank;
		node_i = node_i->next;
	}
	l->dis = 1;
}

int	main(int argc, char *argv[])
{
	int		n;
	list	*l;
	nod		*stack_a;
	tab		*table;

	if (argc <= 1)
		return(0);
	if(check_param(argc, argv) == 0)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
		return(0);
	}
	stack_a = init_stack(argc, argv);
	if (stack_a == NULL)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
		return(0);
	}
	l = init_list(stack_a, argc);
	if (l == NULL)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
		return(0);
	}
	if(check_dup(l) != 0)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
		return(0);
	}
	table = init_tab(l->node_a, (argc - 1));
	if (table == NULL)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
		return(0);
	}
	discret(l);
//	printa(l);
	n = rec_sort(l, table);
	tester(l);
	printf("n = %d\n", n);
	return(1);
}

