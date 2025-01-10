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

typedef struct no
{
	struct no	*next;
	struct no	*prev;
	int			index;
	int			value;
	int			value_init;
	int			discret;
} nod;

typedef struct lis
{
	nod	*node_a;
	nod	*node_b;
	int		dim_a;
	int		dim_b;
	int		dis;
} list;

typedef struct ta
{
	nod		*location;
	int			size;
	pos			position;
	nod		*pivot;
	struct ta	*tp;
	struct ta	*tm;
} tab;


int	ft_atoi(const char *str);

nod		*add_node(nod *node, int value);
list	*init_list(nod *stack, int size);
tab		*init_tab(nod *location, int size);
nod		*init_stack(int argc, char *argv[]);

int		rec_sort(list *l, tab *table);
int		split_a(list *l, tab *table);
int		split_b(list *l, tab *table);

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

int		test_i(list *stack);
void	printa(list *l);
void	tester(list *l);
