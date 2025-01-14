//#ifndef PUSH_SWAP_H
//# define PUSH_SWAP_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#include"ft_printf.h"

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
	int	dim_a;
	int	dim_b;
	int	dis;
} list;

typedef struct ta
{
	nod			*location;
	int			size;
	pos			position;
	nod			*pivot;
	struct ta	*tp;
	struct ta	*tm;
} tab;


int		ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

int		strlen_2(char **argv);
char	**check_param(char **argv, int argc);

nod		*add_node(nod *node, int value);
nod		*free_all_node(nod *node);
list	*init_list(nod *stack, int size);
tab		*init_tab(nod *location, int size);
nod		*init_stack(char *argv[], int size);

void 	error(void);

int		sort(list *l, tab *table);

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
void	print_double_char(char **argv);
void	tester(list *l);
