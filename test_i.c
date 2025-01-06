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

int	bulle_t(list *l)
{
	int	n;
	int c;

	n = 0;
	c = 0;
	while(n<100000)
	{
		if(l->node_a->value > l->node_a->next->value && l->node_a->index != 0)
		{
			sa(l);
			c++;
		}
		ra(l);
		c++;
		n++;
	}
	return (c);
}

int	test2(list *l)
{
	int	n;

	n = 0;
	while (n<500)
	{
		if (l->node_a->value < l->node_a->next->value)
		{
			ra(l);
			ra(l);
		}
		else
		{
			pb(l);
			pb(l);
		}
		n = n + 2;
	}
	while (n < 1000)
	{
		if(l->node_b->value < l->node_a->value)
			pa(l);
		else
			ra(l);
		n++;
	}

	return (n);
}

void	sort_3(list *l, tab table)
{
	int	a;
	int b;
	int c;
	int t;

	printf("sort_3\n");


	if (table.size >= 1)
	{
		a = l->node_a->value;
		printf("a = %d\n", a);
	}
	if (table.size >= 2)
	{
		b = l->node_a->next->value;
		printf("b = %d\n", b);
		if (a > b)
		{
			sa(l);
			t = a;
			a = b;
			b = t;
			printf("a = %d  b = %d \n", a, b);
			printa(l);
		}
	}
	if (table.size == 3)
	{
		c = l->node_a->next->next->value;
		printf("c = %d\n", c);
		if (b > c)
		{
			ra(l);
			sa(l);
			rra(l);
			t = b;
			b = c;
			c = t;
			printf("a = %d  b = %d  c = %d  \n\n", a, b , c);
			printa(l);
		}
		if (a > b )
		{
			sa(l);
			printa(l);
		}
	}
}

node	*find_p(list *l, tab table)
{
	return (table.location);
}

void	to_top_a(list *l, tab table)
{
	int i;

	printf("\nto top\n");
	i = 0;
	//si bas de a
	if(table.stack == 0 && table.location != l->node_a)
	{
		while(i < table.size)
		{
			rra(l);
			i++;
		}
	}
	i = 0;
	//si b
	if(table.stack == 1)
	{
		//si bas
		if(table.location != l->node_b)
		{
			while(i < table.size)
			{
				rrb(l);
				i++;
			}
		}
		i = 0;
		while(i < table.size)
		{
			pa(l);
			i++;
		}
	}
	printa(l);

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
printf("rec_sort\n");
 	//resolution simple
	if (table.size <= 3)
	{
		to_top_a(l, table);
		sort_3(l, table);
	}
	//separation au pivot
	else
	{
		pivot = find_p(l, table);
		printf ("pivot = %d\n", pivot->value);
		//tri par rapport au pivot
		if (table.stack == 0)
		{
			while ((tp.size + tm.size) < table.size)
			{
				if (pivot->value <= l->node_a->value)
				{
					pb(l);
					printa(l);
					tp.size++;
				}
				else
				{
					pb(l);
					printa(l);
					if(tm.size == 0)
						tm.location = l->node_b;
					rb(l);
					printa(l);
					tm.size++;
				}
			}
		tp.location = l->node_b;
		tp.stack = 1;
		tm.stack = 1;
		printf("stack b, tp.loc = %d , tp.size = %d, tm.loc = %d , tm.size = %d \n", tp.location->index, tp.size, tm.location->index, tm.size);
		}
		else
		{
			while ((tp.size + tm.size) < table.size)
			{
				if (pivot->value <= l->node_b->value)
				{
					pa(l);
					printa(l);
					tp.size++;
				}
				else
				{
					pa(l);
					printa(l);
					if(tm.size == 0)
						tm.location = l->node_a;
					ra(l);
					printa(l);
					tm.size++;
				}
			}
		tp.location = l->node_a;
		tp.stack = 0;
		tm.stack = 0;
		printf("stack a, tp.loc = %d , tp.size = %d, tm.loc = %d , tm.size = %d \n", tp.location->index, tp.size, tm.location->index, tm.size);
		}

		rec_sort(l, tp);
		rec_sort(l, tm);

	}
	return (n);
}
