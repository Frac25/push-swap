#include"push_swap.h"

int	test_i(list *stack)
{
	printa(stack);

	sa(stack);
	printa(stack);

	sa(stack);
	printa(stack);

	ra(stack);
	printa(stack);

	ra(stack);
	printa(stack);

	rra(stack);
	printa(stack);

	rra(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	pa(stack);
	printa(stack);

	pa(stack);
	printa(stack);

	pa(stack);
	printa(stack);

	pa(stack);
	printa(stack);

	pa(stack);
	printa(stack);

	pa(stack);
	printa(stack);

	pa(stack);
	printa(stack);

	pa(stack);
	printa(stack);

	pa(stack);
	printa(stack);

	pa(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	pb(stack);
	printa(stack);

	ss(stack);
	printa(stack);

	rr(stack);
	printa(stack);

	rra(stack);
	printa(stack);

	rrb(stack);
	printa(stack);

	rrr(stack);
	printa(stack);

	return(0);
}

int	sort_3(list *l, tab table)
{
	int	a;
	int b;
	int c;
	int t;
	int n;

//	printf("sort_3\n");
	n = 0;
	if (table.size >= 1)
		a = l->node_a->value;
	if (table.size >= 2)
	{
		b = l->node_a->next->value;
		if (a > b)
		{
			n += sa(l);
			t = a;
			a = b;
			b = t;
		}
	}
	if (table.size == 3)
	{
		c = l->node_a->next->next->value;
		if (b > c)
		{
			n += ra(l);
			n += sa(l);
			n += rra(l);
			t = b;
			b = c;
			c = t;
		}
		if (a > b )
		{
			n += sa(l);
		}
	}
	return (n);
}

node *p_moyen(list *l, tab table)
{
	int		i;
	int		somme_p;
	int		valeur_p;
	node	*location_t;

	i = 0;
	somme_p = 0;
	location_t = table.location;
	while(i < table.size)
	{
		somme_p += location_t->discret;
		location_t = location_t->next;
		i++;
	}
	valeur_p = (somme_p / i);

	location_t = table.location;
	while(location_t->discret != valeur_p) //i < table.size &&
		location_t = location_t->next;
	return (location_t);
}

node	*find_p(list *l, tab table)
{
	if(l->dis == 1)
		return(p_moyen(l, table));
	if(table.position == u_a)
		return(l->node_a);
	if(table.position == u_b)
		return(l->node_b);
	if(table.position == d_a)
		return(l->node_a->prev);
	if(table.position == d_b)
		return(l->node_b->prev);
	return(NULL);
}

int	to_top_a(list *l, tab table)
{
	int i;
	int n;

//	printf("\nto top\n");
	i = 0;
	n = 0;
	if(table.position == d_a)
	{
		while(i < table.size)
		{
			n += rra(l);
			i++;
		}
	}
	i = 0;
	if(table.position == d_b)
	{
		while(i < table.size)
		{
			n += rrb(l);
			n += pa(l);
			i++;
		}
	}
	i = 0;
	if(table.position == u_b)
	{
		while(i < table.size)
		{
			n += pa(l);
			i++;
		}
	}
	return (n);
}

int	rec_sort(list *l, tab table)
{
	int		n;
	node	*pivot;
	tab		tp;
	tab		tm;

	n = 0;
	tp.size = 0;
	tm.size = 0;
//printf("rec_sort\n");
 	//resolution simple
	if (table.size <= 3)
	{
		n += to_top_a(l, table);
		n += sort_3(l, table);
	}
	//split
	else
	{
		pivot = find_p(l, table);
//		printf ("pivot = %d\n", pivot->value);
		//tri par rapport au pivot
		if (table.position == u_a)
		{
			while ((tp.size + tm.size) < table.size)
			{
				if (pivot->value <= l->node_a->value)
				{
					n += pb(l);
					tp.size++;
					tp.location = l->node_b;
				}
				else
				{
					n += pb(l);
					if(tm.size == 0)
						tm.location = l->node_b;
					n += rb(l);
					tm.size++;
				}
			}
		tp.position = u_b;
		tm.position = d_b;
//		printf("tp.pos = %u , tp.loc = %d , tp.size = %d, tm.loc = %d , tm.size = %d \n", tp.position, tp.location->index, tp.size, tm.location->index, tm.size);
		}
		if (table.position == u_b)
		{
			while ((tp.size + tm.size) < table.size)
			{
				if (pivot->value <= l->node_b->value)
				{
					n += pa(l);
					tp.size++;
					tp.location = l->node_a;
				}
				else
				{
					n += pa(l);
					if(tm.size == 0)
						tm.location = l->node_a;
					n += ra(l);
					tm.size++;
				}
			}

		tp.position = u_a;
		tm.position = d_a;
//		printf("tp.pos = %u , tp.loc = %d , tp.size = %d, tm.loc = %d , tm.size = %d \n", tp.position, tp.location->index, tp.size, tm.location->index, tm.size);
		}
		if (table.position == d_a)
		{
			while ((tp.size + tm.size) < table.size)
			{
				n += rra(l);
				if (pivot->value <= l->node_a->value)
				{
					n += pb(l);
					tp.size++;
					tp.location = l->node_b;
				}
				else
				{
					n += pb(l);
					if(tm.size == 0)
						tm.location = l->node_b;
					n += rb(l);
					tm.size++;
				}
			}
		tp.position = u_b;
		tm.position = d_b;
//		printf("tp.pos = %u , tp.loc = %d , tp.size = %d, tm.loc = %d , tm.size = %d \n", tp.position, tp.location->index, tp.size, tm.location->index, tm.size);
		}
		if (table.position == d_b)
		{
			while ((tp.size + tm.size) < table.size)
			{
				n += rrb(l);
				if (pivot->value <= l->node_b->value)
				{
					n += pa(l);
					tp.size++;
					tp.location = l->node_a;
				}
				else
				{
					n += pa(l);
					if(tm.size == 0)
						tm.location = l->node_a;
					n += ra(l);
					tm.size++;
				}
			}
		tp.position = u_a;
		tm.position = d_a;
//		printf("tp.pos = %u , tp.loc = %d , tp.size = %d, tm.loc = %d , tm.size = %d \n", tp.position, tp.location->index, tp.size, tm.location->index, tm.size);
		}
		n += rec_sort(l, tp);
		n += rec_sort(l, tm);
	}

	return (n);
}
