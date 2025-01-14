#include"push_swap.h"

int check_argc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

char **check_param(char **argv, int argc)
{
	int		i;
	int		j;

	argv = &argv[1];
	if(argc == 2)
		argv = ft_split(argv[0], ' ');
	argc = check_argc(argv);




	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '+' || argv[i][0] == '-')
			j++;
		if (argv[i][j] < '0' || argv[i][j] > '9')
			error();
		j++;
		while(argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				error();
			j++;
		}
		i++;
	}
	return(argv);
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
