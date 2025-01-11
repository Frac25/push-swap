#include"push_swap.h"

int	pa(list *l)
{
	nod *a1;
	nod *bn1;

	if (l->node_a == NULL)
	{
		bn1 = l->node_b->next;
		l->node_b->next->prev = l->node_b->prev;
		l->node_b->prev->next = l->node_b->next;
		l->node_a = l->node_b;
		l->node_a->next = l->node_b;
		l->node_a->prev = l->node_b;
		l->node_b = bn1;
	}
	else if (l->node_b->next == l->node_b)
	{
		a1 = l->node_a;
		l->node_a = l->node_b;
		l->node_a->next = a1;
		l->node_a->prev = a1->prev;
		l->node_a->next->prev = l->node_a;
		l->node_a->prev->next = l->node_a;
		l->node_b = NULL;
	}
	else
	{
		bn1 = l->node_b->next;
		l->node_b->next->prev = l->node_b->prev;
		l->node_b->prev->next = l->node_b->next;
		a1 = l->node_a;
		l->node_a = l->node_b;
		l->node_a->next = a1;
		l->node_a->prev = a1->prev;
		l->node_a->next->prev = l->node_a;
		l->node_a->prev->next = l->node_a;
		l->node_b = bn1;
	}
	ft_printf("pa\n");
	return(1);
}

int	pb(list *l)
{
	nod *b1;
	nod *an1;

	if (l->node_b == NULL)
	{
		an1 = l->node_a->next;
		l->node_a->next->prev = l->node_a->prev;
		l->node_a->prev->next = l->node_a->next;
		l->node_b = l->node_a;
		l->node_b->next = l->node_a;
		l->node_b->prev = l->node_a;
		l->node_a = an1;
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
	}
	ft_printf("pb\n");
	return(1);
}

int	sa(list *l)
{
	nod	*node_tmp;

	node_tmp = l->node_a->next;
	l->node_a->prev->next = l->node_a->next;
	l->node_a->next->prev = l->node_a->prev;
	l->node_a->next->next->prev = l->node_a;
	l->node_a->next = l->node_a->next->next;
	l->node_a->prev = node_tmp;
	node_tmp->next = l->node_a;
	l->node_a = node_tmp;
	ft_printf("sa\n");
	return(1);
}

int	sb(list *l)
{
	nod	*node_tmp;

	node_tmp = l->node_b->next;
	l->node_b->prev->next = l->node_b->next;
	l->node_b->next->prev = l->node_b->prev;
	l->node_b->next->next->prev = l->node_b;
	l->node_b->next = l->node_b->next->next;
	l->node_b->prev = node_tmp;
	node_tmp->next = l->node_b;
	l->node_b = node_tmp;
	ft_printf("sb\n");
	return(1);
}

int	ss(list *l)
{
	nod	*node_tmp;

	node_tmp = l->node_a->next;
	l->node_a->prev->next = l->node_a->next;
	l->node_a->next->prev = l->node_a->prev;
	l->node_a->next->next->prev = l->node_a;
	l->node_a->next = l->node_a->next->next;
	l->node_a->prev = node_tmp;
	node_tmp->next = l->node_a;
	l->node_a = node_tmp;
	node_tmp = l->node_b->next;
	l->node_b->prev->next = l->node_b->next;
	l->node_b->next->prev = l->node_b->prev;
	l->node_b->next->next->prev = l->node_b;
	l->node_b->next = l->node_b->next->next;
	l->node_b->prev = node_tmp;
	node_tmp->next = l->node_b;
	l->node_b = node_tmp;
	ft_printf("ss\n");
	return(1);
}
