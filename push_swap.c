#include"push_swap.h"

void	discret(list *l, tab *table)
{
	int	i;
	nod	*node_t;
	tab	*table_t;

	rec_sort(l, table);
	i = 1;
	node_t = l->node_a;
	while(i++ < l->dim_a)
	{
		node_t->discret = i;
		node_t->value = node_t->index + 1;
		node_t = node_t->next;
	}
	table_t = init_tab(l->node_a, l->dim_a - 1);
	rec_sort(l, table_t);
	i = 1;
	node_t = l->node_a;
	while(i++ < l->dim_a)
	{
		node_t->value = node_t->value_init;
		node_t = node_t->next;
	}
	l->dis = 1;
}

int	main(int argc, char *argv[])
{
	int		n;
	list	*l;
	nod		*stack_a;
	tab		*table;

	stack_a = init_stack(argc, argv);
	l = init_list(stack_a, argc);
	printa(l);
//	test_i(l);
	table = init_tab(l->node_a, (argc - 1));
	discret(l, table);
//	fd = open("resultat.txt", O_WRONLY);
	n = rec_sort(l, table);

	printa(l);
	tester(l);
	printf("n = %d\n", n);
//	close(fd);
	return(0);
}

