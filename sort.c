#include"push_swap.h"
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

int	sort_123(list *l, tab *table)
{
	int n;

	n = 0;
	if (table->size == 2 && (l->node_a->value > l->node_a->next->value))
		n += sa(l);
	if (table->size == 3)
		n += sort_3(l);
	return (n);
}

int	sort(list *l, tab *table)
{
	int	n;

	discret(l);
	n = rec_sort(l, table);
	return (n);
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

int	sort_5(list *l)
{
	int	n;

	n = 0;
	n = l->dim_a;
	printf("s5\n");

	return (n);
}

