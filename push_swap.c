#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"push_swap.h"

void	swap(list *l)
{
	int	value_tmp;

	value_tmp = l->node_a->value;
	l->node_a->value = l->node_a->next->value;
	l->node_a->next->value = value_tmp;
}

void	rotate(list *l)
{
	l->node_a = l->node_a->next;
}

void	rrotate(list *l)
{
	l->node_a = l->node_a->prev;
}

void	push_ab(list *l)
{
	node *b1;
	node *an1;

	if (l->node_b == NULL)
	{
		an1 = l->node_a->next;
		l->node_a->next->prev = l->node_a->prev;
		l->node_a->prev->next = l->node_a->next;

		l->node_b = l->node_a;
		l->node_b->next = l->node_a;
		l->node_b->prev = l->node_a;

		l->node_a = an1;


printf("cas1\n");
	}
	else if (l->node_a->next == l->node_a)
	{
		b1 = l->node_b;
		l->node_b = l->node_a;
		l->node_b->next = b1;
		l->node_b->prev = b1->prev;
		l->node_b->next->prev = l->node_b;
		l->node_b->prev->next = l->node_b;

		l->node_a = NULL;
printf("cas2\n");
	}
	else
	{
		an1 = l->node_a->next;
		l->node_a->next->prev = l->node_a->prev;
		l->node_a->prev->next = l->node_a->next;

		b1 = l->node_b;
		l->node_b = l->node_a;
		l->node_b->next = b1;
		l->node_b->prev = b1->prev;
		l->node_b->next->prev = l->node_b;
		l->node_b->prev->next = l->node_b;

		l->node_a = an1;
printf("cas3\n");
	}
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

	printa(stack_a);

	swap(stack_a);
	printa(stack_a);

	rotate(stack_a);
	printa(stack_a);

	rotate(stack_a);
	printa(stack_a);

	rrotate(stack_a);
	printa(stack_a);

	rrotate(stack_a);
	printa(stack_a);

	push_ab(stack_a);
	printa(stack_a);

	push_ab(stack_a);
	printa(stack_a);

	return(0);
}

