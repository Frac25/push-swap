#include"push_swap.h"

int	rra(list *l)
{
	l->node_a = l->node_a->prev;
	ft_printf("rra\n");
	return(1);
}

int	rrb(list *l)
{
	l->node_b = l->node_b->prev;
	ft_printf("rrb\n");
	return(1);
}

int	rrr(list *l)
{
	l->node_a = l->node_a->prev;
	l->node_b = l->node_b->prev;
	ft_printf("rrr\n");
	return(1);
}
