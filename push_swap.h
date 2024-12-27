//#ifndef PUSH_SWAP_H
//# define PUSH_SWAP_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct nod
{
	int			value;
	struct nod	*next;
	struct nod	*prev;
	int			index;
} node;

typedef struct lis
{
	node	*node_a;
	node	*node_b;
	int		dim_a;
	int		dim_b;
} list;


int	ft_atoi(const char *str);

node	*add_node(node *first_node, int value);
list	*init_list(node *n, int arg);

void	printl_e(list *l1, list *l2);
void	printl_e1(list *l1);
void	printl_a1(list *l1);
void	printl_a2(list *l1, list *l2);
void	printa(list *l);

void	sa(list *l);
void	sb(list *l);
void	ss(list *l);
void	pa(list *l);
void	pb(list *l);
void	ra(list *l);
void	rb(list *l);
void	rr(list *l);
void	rra(list *l);
void	rrb(list *l);
void	rrr(list *l);

int	test_i(list *stack);
