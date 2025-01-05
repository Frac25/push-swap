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

typedef struct ta
{
	node	*location;
	int		size;
	char	stack;
} tab;


int	ft_atoi(const char *str);

node	*add_node(node *first_node, int value);
list	*init_list(node *n, int arg);

void	printa(list *l);
void	tester(list *l);

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
int	bulle_t(list *l);
int	test2(list *l);
int	rec_sort(list *l, tab *table);
