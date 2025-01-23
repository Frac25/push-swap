#include "push_swap.h"

int	sort_ub_r3(t_list *l)
{
	int	n;
	int a = l->node_b->value;
	int b = l->node_b->next->value;
	int c = l->node_b->next->next->value;

	n = 0;
	if      (c > b && b > a)
		n += rb(l) + sb(l) + pa(l) + pa(l) + rrb(l) + pa(l);
	else if (b > c && c > a)
		n += rb(l) + pa(l) + pa(l) + rrb(l) + pa(l);
	else if (c > a && a > b)
		n += rb(l) + sb(l) + pa(l) + rrb(l) + pa(l) + pa(l);
	else if (b > a && a > c)
		n += sb(l) + pa(l) + pa(l) + pa(l);
	else if (a > c && c > b)
		n += pa(l) + sb(l) + pa(l) + pa(l);
	else if (a > b && b > c)
		n += pa(l) + pa(l) + pa(l);
	return (n);
}

int	sort_db_r3(t_list *l)
{
	int	n;
	int a = l->node_b->prev->prev->prev->value;
	int b = l->node_b->prev->prev->value;
	int c = l->node_b->prev->value;

	n = 0;
	if      (c > b && b > a)
		n += rrb(l) + pa(l) + rrb(l) + pa(l) + rrb(l) + pa(l);
	else if (b > c && c > a)
		n += rrb(l) + rrb(l) + pa(l) + pa(l) + rrb(l) + pa(l);
	else if (c > a && a > b)
		n += rrb(l) + pa(l) + rrb(l) + rrb(l) + pa(l) + pa(l);
	else if (b > a && a > c)
		n += rrb(l) + rrb(l) + pa(l) + rrb(l) + pa(l) + pa(l);
	else if (a > c && c > b)
		n += rrb(l) + rrb(l) + rrb(l) + pa(l) + sb(l) + pa(l) + pa(l);
	else if (a > b && b > c)
		n += rrb(l) + rrb(l) + rrb(l) + pa(l) + pa(l) + pa(l);
	return (n);
}

int	sort_da_r3(t_list *l)
{
	int	n;
	int a = l->node_b->prev->prev->prev->value;
	int b = l->node_b->prev->prev->value;
	int c = l->node_b->prev->value;

	n = 0;
	if      (c > b && b > a)
		n += rra(l) + rra(l) + rra(l);
	else if (b > c && c > a)
		n += rra(l) + rra(l) + sa(l) + rra(l);
	else if (c > a && a > b)
		n += rra(l) + rra(l) + rra(l) + sa(l);
	else if (b > a && a > c)
		n += rra(l) + rra(l) + sa(l) + rra(l) + sa(l);
	else if (a > c && c > b)
		n += rra(l) + rra(l) + pb(l) + rra(l) + sa(l) + pa(l);
	else if (a > b && b > c)
		n += rra(l) + pb(l) + rra(l) + rra(l) + sa(l) + pa(l);
	return (n);
}
