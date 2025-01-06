#include"push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	list	*l;
	node	*node_a;
	node	*node_a1;

	node_a = add_node(NULL,ft_atoi(argv[argc - 1]));
	node_a1 = node_a;
	i = argc -2;;
	while (i > 0)
	{
		node_a = add_node(node_a, ft_atoi(argv[i]));
		i--;
	}
	node_a->prev = node_a1;
	node_a1->next = node_a;

	l = init_list(node_a, argc);
	printa(l);
//	test_i(l);
//	i = bulle_t(l);

//	i = test2(l);

	tab	table;
	table.location = l->node_a;
	printf("argc = %d \n", argc);
	table.size = argc -1;
	table.position = u_a;


	i = rec_sort(l, table);


	printa(l);

//	tester(l);

	printf("\ni = %d\n", i);

	return(0);
}

