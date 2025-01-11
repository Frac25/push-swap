#include"push_swap.h"

nod *p_moyen(tab *table)
{
	int		i;
	int		somme_p;
	int		valeur_p;
	nod	*location_t;

	i = 0;
	somme_p = 0;
	location_t = table->location;
	while(i < table->size)
	{
		somme_p += location_t->discret;
		location_t = location_t->next;
		i++;
	}
	valeur_p = (somme_p / i);
	location_t = table->location;
	while(location_t->discret != valeur_p)
		location_t = location_t->next;
	return (location_t);
}

nod	*find_p(list *l, tab *table)
{
	if(l->dis == 1)
		return(p_moyen(table));
	if(table->position == u_a)
		return(l->node_a);
	if(table->position == u_b)
		return(l->node_b);
	if(table->position == d_a)
		return(l->node_a->prev);
	if(table->position == d_b)
		return(l->node_b->prev);
	return(NULL);
}

int	to_top_a(list *l, tab *table)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if(table->position == d_a)
		while(i < table->size)
		{
			n += rra(l);
			i++;
		}
	if(table->position == d_b)
		while(i < table->size)
		{
			n += rrb(l);
			n += pa(l);
			i++;
		}
	if(table->position == u_b)
		while(i < table->size)
		{
			n += pa(l);
			i++;
		}
	return (n);
}

int	sort_r3(list *l, tab *table)
{
	int n;

	n = 0;
	if (table->size >= 2 && (l->node_a->value > l->node_a->next->value))
			n += sa(l);
	if (table->size == 3)
	{
		if (l->node_a->next->value > l->node_a->next->next->value)
		{
			n += ra(l);
			n += sa(l);
			n += rra(l);
		}
		if (l->node_a->value > l->node_a->next->value)
			n += sa(l);
	}
	return (n);
}

int	rec_sort(list *l, tab *table)
{
	int	n;

	n = 0;
	if (table->size <= 3) //resolution simple
	{
		n += to_top_a(l, table);
		n += sort_r3(l, table);
	}
		else //split
	{
		table->tm = init_tab(NULL,0);
		table->tp = init_tab(NULL,0);
		table->pivot = find_p(l, table);
		if (table->position == u_a || table->position == d_a)
			n += split_a(l, table);
		else
			n += split_b(l, table);
		n += rec_sort(l, table->tp);
		n += rec_sort(l, table->tm);
//		free(table->tm);
//		free(table->tp);
	}
	return (n);
}
