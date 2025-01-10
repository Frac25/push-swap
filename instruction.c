#include"push_swap.h"

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
	printf("sa\n");
	write(fd, "sa\n", 3);
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
	printf("sb\n");
	write(fd, "sb\n", 3);
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
	printf("ss\n");
	write(fd, "ss\n", 3);
	return(1);
}

int	ra(list *l)
{
	l->node_a = l->node_a->next;
	printf("ra\n");
	write(fd, "ra\n", 3);
	return(1);
}

int	rb(list *l)
{
	l->node_b = l->node_b->next;
	printf("rb\n");
	write(fd, "rb\n", 3);
	return(1);
}

int	rr(list *l)
{
	l->node_a = l->node_a->next;
	l->node_b = l->node_b->next;
	printf("rr\n");
	write(fd, "rr\n", 3);
	return(1);
}

int	rra(list *l)
{
	l->node_a = l->node_a->prev;
	printf("rra\n");
	write(fd, "rra\n", 4);
	return(1);
}

int	rrb(list *l)
{
	l->node_b = l->node_b->prev;
	printf("rrb\n");
	write(fd, "rrb\n", 4);
	return(1);
}

int	rrr(list *l)
{
	l->node_a = l->node_a->prev;
	l->node_b = l->node_b->prev;
	printf("rrr\n");
	write(fd, "rrr\n", 4);
	return(1);
}

int	pa(list *l)
{
	nod *a1;
	nod *bn1;

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
	write(fd, "pa\n", 3);
	return(1);
}

int	pb(list *l)
{
	nod *b1;
	nod *an1;

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
	write(fd, "pb\n", 3);
	return(1);
}
