#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"push_swap.h"

void	swap(list *l)
{
	int	tvalue;

	tvalue = l->node_1->value;
	l->node_1->value = l->node_2->value;
	l->node_2->value = tvalue;
}

void	push(list *a, list *b)
{
	a->node_1->next = b->node_1;
	b->node_2 = b->node_1;
	b->node_1 = a->node_1;

	a->node_1 = a->node_2;
	a->node_2 = a->node_1->next;
}

void	rotate(list *a)
{
	a->node_n->next = a->node_1;
	a->node_1->next = NULL;

	a->node_m = a->node_n;
	a->node_n = a->node_1;

	a->node_1 = a->node_2;
	a->node_2 = a->node_1->next;
}

void	rrotate(list *a)
{
	a->node_n->next = a->node_1;
	a->node_m->next = NULL;

	a->node_1 = a->node_n;
	a->node_2 = a->node_1->next;

	a->node_n = a->node_m;
	a->node_m = NULL;
}

int	main(int argc, char *argv[])
{
	int		i;
	list	*stack_a;
	list	*stack_b;
	node	*node_a;
	node	*node_b;

	node_a = add_node(NULL,ft_atoi(argv[argc - 1]));
	node_b = add_node(NULL,0);
	i = argc -2;;
	while (i > 0)
	{
		node_a = add_node(node_a, ft_atoi(argv[i]));
		node_b = add_node(node_b, 0);
		i--;
	}
	stack_a = init_list(node_a, argc);
	stack_b = init_list(node_b, argc);

	printl_a(stack_a, stack_b);
//	printl_e(stack_a, stack_b);

	swap(stack_a);
	printl_a(stack_a, stack_b);

	push(stack_a, stack_b);
	printl_a(stack_a, stack_b);

	push(stack_a, stack_b);
	printl_a(stack_a, stack_b);

	push(stack_a, stack_b);
	printl_a(stack_a, stack_b);

	rotate(stack_a);
	printl_a(stack_a, stack_b);

	rotate(stack_a);
	printl_a(stack_a, stack_b);

	rotate(stack_a);
	printl_a(stack_a, stack_b);

	rrotate(stack_a);
	printl_a(stack_a, stack_b);

	return(0);
}
