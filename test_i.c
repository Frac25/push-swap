#include"push_swap.h"

int	test_i(list *stack)
{
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

	rr(stack);
	printa(stack);

	rr(stack);
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

void	sort3(list *l, tab *table)
{
	int	a;
	int b;
	int c;

	a = table->location->value;
	if (table->size == 1)
	{
		pb(l);
	}
	if (table->size == 2)
	{
		b = table->location->next;
		if (b > a)
			sb(l);
		pb(l);
		pb(l);
	}
	else
	{
		c = table->location->next->next;
		if (b > a)
			sb(l);
		if (c > b)
			sb(l);
		if (c > a)
			sb(l);
		pb(l);
		pb(l);
		pb(l);
	}
}

node	*find_p(list *l, tab *table)
{
	return (table->location->value);
}

int	rec_sort(list *l, tab *table)
{
	int		n;
	node	*pivot;
	tab		tp;
	tab		tm;

	n = 0;
	tp->size = 0;
	tm->size = 0;

 	//resolution simple
	if (table->size <= 3)
		sort_3(l);
	//separation au pivot
	else
	{
		pivot = find_p(*l, *table);
		//tri par rapport au pivot
		if (table->stack == "a"){
		while (n < table->size)
		{
			if (pivot->value <= l->node_a->value)
			{
				pb(l);
				tp->size++;
			}
			else
			{
				pb(l);
				if(tm->size == 0)
					tm->location = l->node_b;
				rrb(l);
				tm->size++;
			}
		}
		tp->location = l->node_b;
		tp->stack = "b";
		tm->stack = "b";
		}
		else{
		while (n < table->size)
		{
			if (pivot->value <= l->node_b->value)
			{
				pa(l);
				tp->size++;
			}
			else
			{
				pa(l);
				if(tm->size == 0)
					tm->location = l->node_b;
				rra(l);
				tm->size++;
			}
		}
		tp->location = l->node_b;
		tp->stack = "a";
		tm->stack = "a";
		}

		rec_sort(l, tp);
		rec_sort(l, tm);
	}
	return (n);
}
