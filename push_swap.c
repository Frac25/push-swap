#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"push_swap.h"

void	swap(list *l)
{
	l->node_2->next->prev = l->node_1;
	l->node_1->prev->next = l->node_2;
	l->node_2->prev = l->node_1->prev;
	l->node_1->next = l->node_2->next;
	l->node_1->prev = l->node_2;
	l->node_2->next = l->node_1;

	l->node_1 = l->node_2;
	l->node_2 = l->node_2->next;
}

void	rotate(list *l)
{
	l->node_1 = l->node_2;
	l->node_2 = l->node_1->next;
}

void	rrotate(list *l)
{
	l->node_1 = l->node_1->prev;
	l->node_2 = l->node_2->prev;
}

int	main(int argc, char *argv[])
{
	int		i;
	list	*stack_a;
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

	stack_a = init_list(node_a, argc);

	printn(stack_a);

	swap(stack_a);
	printn(stack_a);

	rotate(stack_a);
	printn(stack_a);

	rotate(stack_a);
	printn(stack_a);

	rrotate(stack_a);
	printn(stack_a);

	rrotate(stack_a);
	printn(stack_a);

	return(0);
}


/*
void	push(list *a, list *b)
{
	a->node_1->next = b->node_1;
	b->node_2 = b->node_1;
	b->node_1 = a->node_1;

	a->node_1 = a->node_2;
	a->node_2 = a->node_1->next;
}

*/
