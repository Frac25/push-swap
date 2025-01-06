#include"push_swap.h"

void	discret(list *l)
{
	int		i;
	node	*n;
	tab		table;

	i = 1;
	n = l->node_a;
	while(i < l->dim_a)
	{
		n->discret = i;
		n->value_init = n->value;
		n->value = n->index + 1;
		i++;
		n = n->next;
	}

	table.location = l->node_a;
	table.size = l->dim_a - 1;
	table.position = u_a;

	printf("discret :\n");
	printa(l);
	rec_sort(l, table);

	i = 1;
	n = l->node_a;
	while(i < l->dim_a)
	{
		n->value = n->value_init;
		i++;
		n = n->next;
	}
	l->dis = 1;
}


int	main(int argc, char *argv[])
{
	int		i;
	int		n;
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

	tab	table;
	table.location = l->node_a;
	table.size = argc -1;
	table.position = u_a;
	n = rec_sort(l, table);

	discret(l);
	fd = open("resultat.txt", O_WRONLY);
	table.location = l->node_a;
	table.size = argc -1;
	table.position = u_a;
	n = rec_sort(l, table);

	printa(l);
	printf("dernier tri\n");
	tester(l);
	printf("n = %d\n", n);

	close(fd);
	return(0);
}

