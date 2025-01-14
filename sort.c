#include"push_swap.h"

int	ever_sorted(list *l)
{
	nod	*nt;
	int	i;

	nt = l->node_a;
	i = 0;
	while (nt != l->node_a->prev)
	{
		if (nt->value < nt->next->value)
			i++;
		else
			return(0);
		nt = nt->next;
	}
	return (1);
}

void	discret(list *l)
{
	int j;
	int rank;
	nod	*node_i;
	nod	*node_j;

	node_i = l->node_a;
	node_j = l->node_a;
	while (node_i->discret == 0)
	{
		rank = 0;
		j = 0;
		while (j < l->dim_a)
		{
			if (node_i->value >= node_j->value)
				rank++;
			j++;
			node_j = node_j->next;
		}
		node_i->discret = rank;
		node_i = node_i->next;
	}
	l->dis = 1;
}

int	sort_3(list *l)
{
	int	n;
	int	a;
	int	b;
	int	c;

	a = l->node_a->value;
	b = l->node_a->next->value;
	c = l->node_a->next->next->value;
	n = 0;
	if (a > b && b > c)
		n += ra(l);
	if (a > b && b > c)
		n += sa(l);
	if (a > b && b < c && a > c)
		n += ra(l);
	if (a > b && b < c && a < c)
		n += sa(l);
	if (a < b && b > c && a > c)
		n += rra(l);
	if (a < b && b > c && a < c)
		n += rra(l);
	if (a < b && b > c && a < c)
		n += sa(l);
	return (n);
}

int	sort_1to5(list *l)
{
	int n;

	n = 0;
	if (l->dim_a == 2 && (l->node_a->value > l->node_a->next->value))
		n += sa(l);
	else if (l->dim_a == 3)
		n += sort_3(l);
	else if (l->dim_a == 4 || l->dim_a == 5)
	{
		while (l->dim_a > 3)
			if (l->node_a->discret < 3)
				n += pb(l);
			else
				n += ra(l);
		if (l->node_b->discret < l->node_b->next->discret)
			n += sb(l);
		sort_3(l);
		while (l->dim_b > 0)
			n += pa(l);
	}
	return (n);
}

int	sort(list *l, tab *table)
{
	int	n;

	if(check_dup(l) != 0)
		error();
	if (ever_sorted(l) == 1)
		exit(EXIT_SUCCESS);
	discret(l);
	if (l->dim_a <= 5)
		n = sort_1to5(l);
	else
		n = rec_sort(l, table);
	return (n);
}
