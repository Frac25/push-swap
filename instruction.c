#include"push_swap.h"

void	sa(list *l)
{
	node	*node_tmp;

	node_tmp = l->node_a->next;
	l->node_a->prev->next = l->node_a->next;
	l->node_a->next->prev = l->node_a->prev;
	l->node_a->next->next->prev = l->node_a;
	l->node_a->next = l->node_a->next->next;
	l->node_a->prev = node_tmp;
	node_tmp->next = l->node_a;
	l->node_a = node_tmp;
	printf("sa\n");
}

void	sb(list *l)
{
	node	*node_tmp;

	node_tmp = l->node_b->next;
	l->node_b->prev->next = l->node_b->next;
	l->node_b->next->prev = l->node_b->prev;
	l->node_b->next->next->prev = l->node_b;
	l->node_b->next = l->node_b->next->next;
	l->node_b->prev = node_tmp;
	node_tmp->next = l->node_b;
	l->node_b = node_tmp;
	printf("sb\n");
}

void	ss(list *l)
{
	node	*node_tmp;

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

	printf("ss\n");
}

void	ra(list *l)
{
	l->node_a = l->node_a->next;
	printf("ra\n");
}

void	rb(list *l)
{
	l->node_b = l->node_b->next;
	printf("rb\n");
}

void	rr(list *l)
{
	l->node_a = l->node_a->next;
	l->node_b = l->node_b->next;
	printf("rr\n");
}

void	rra(list *l)
{
	l->node_a = l->node_a->prev;
	printf("rra\n");
}

void	rrb(list *l)
{
	l->node_b = l->node_b->prev;
	printf("rrb\n");
}

void	rrr(list *l)
{
	l->node_a = l->node_a->prev;
	l->node_b = l->node_b->prev;
	printf("rrr\n");
}

void	pa(list *l)
{
	node *a1;
	node *bn1;

	printf("pa\n");
	if (l->node_b == NULL)
	{
		printf("cas0 pile b nulle\n");
	}
	else if (l->node_a == NULL)
	{
//		printf("cas1 : pile a nulle\n");
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
//		printf("cas2 pile b va etre null\n");
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
//		printf("cas3 :  a et b non nul\n");
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
}

void	pb(list *l)
{
	node *b1;
	node *an1;

	printf("pb\n");
	if (l->node_a == NULL)
	{
//		printf("cas0 pile a nulle\n");
	}
	else if (l->node_b == NULL)
	{
//		printf("cas1 : pile b nulle\n");
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
//		printf("cas2 pile a va etre null\n");
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
//		printf("cas3 :  a et b non nul\n");
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
}
