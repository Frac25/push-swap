#include"push_swap.h"

char **check_param(char **argv, int argc)
{
	int		i;
	int		j;
	char	**argv2;

	argv2 = argv;
	if(argc == 2)
	{
		argv2 = ft_split(argv[1], ' ');
	}

	i = 1;
	while (i <= argc -1)
	{
		j = 0;
		if (argv2[i][0] == '+' || argv2[i][0] == '-')
			j++;
		if (argv2[i][j] < '0' || argv2[i][j] > '9')
			error();
		j++;
		while(argv2[i][j] != '\0')
		{
			if (argv2[i][j] < '0' || argv2[i][j] > '9')
				error();
			j++;
		}
		i++;
	}
	return(argv2);
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
	char	**param;

	n = 0;
	param = NULL;
	if (argc <= 1)
		return(0);

		printf("argv[0][0] = %c\n", argv[0][0]);
		printf("argv[0][1] = %c\n", argv[0][1]);
		printf("argv[1][0] = %c\n", argv[1][0]);
		printf("argv[1][1] = %c\n", argv[1][1]);
		printf("argv[1][2] = %c\n", argv[1][2]);


	param = check_param(argv, argc);


		printf("param[0][0] = %c\n", param[0][0]);
		printf("param[0][1] = %c\n", param[0][1]);
		printf("param[1][0] = %c\n", param[1][0]);
		printf("param[1][1] = %c\n", param[1][1]);
		printf("param[1][2] = %c\n", param[1][2]);

	stack_a = init_stack(param, argc - 1);
	l = init_list(stack_a, argc - 1);
	if (l == NULL)
	{
		free_all_node(stack_a);
		error();
	}
	table = init_tab(l->node_a, (argc - 1));
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

