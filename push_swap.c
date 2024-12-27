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

	//test_i(l));

	printa(l);

	int n = 0;
	while(n<100)
	{
		if(l->node_a->value > l->node_a->next->value)
			sa(l);
		ra(l);
		n++;
	}
	printa(l);

	return(0);
}

