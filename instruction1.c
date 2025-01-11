#include"push_swap.h"

int	ra(list *l)
{
	l->node_a = l->node_a->next;
	ft_printf("ra\n");
	return(1);
}

int	rb(list *l)
{
	l->node_b = l->node_b->next;
	ft_printf("rb\n");
	return(1);
}

int	rr(list *l)
{
	l->node_a = l->node_a->next;
	l->node_b = l->node_b->next;
	ft_printf("rr\n");
	return(1);
}
