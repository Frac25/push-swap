//#ifndef PUSH_SWAP_H
//# define PUSH_SWAP_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include<fcntl.h> // pour la fct open
int	fd; // pour ecrire

typedef enum po
{
	u_a,
	d_a,
	u_b,
	d_b,
} pos;

typedef struct nod
{
	int			value;
	struct nod	*next;
	struct nod	*prev;
	int			index;
	int			value_init;
	int			discret;
} node;

typedef struct lis
{
	node	*node_a;
	node	*node_b;
	int		dim_a;
	int		dim_b;
	int		dis;
} list;

typedef struct ta
{
	node	*location;
	int		size;
	pos		position;
} tab;


int	ft_atoi(const char *str);

node	*add_node(node *first_node, int value);
list	*init_list(node *n, int arg);

void	printa(list *l);
void	tester(list *l);

int		sa(list *l);
int		sb(list *l);
int		ss(list *l);
int		pa(list *l);
int		pb(list *l);
int		ra(list *l);
int		rb(list *l);
int		rr(list *l);
int		rra(list *l);
int		rrb(list *l);
int		rrr(list *l);

int	test_i(list *stack);
int	rec_sort(list *l, tab table);
