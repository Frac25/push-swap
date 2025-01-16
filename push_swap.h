/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:40:44 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/16 09:59:46 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<string.h>
# include"ft_printf.h"

typedef enum pos
{
	u_a,
	d_a,
	u_b,
	d_b,
}	t_pos;

typedef struct nod
{
	struct nod	*next;
	struct nod	*prev;
	int			index;
	int			value;
	int			value_init;
	int			discret;
}	t_nod;

typedef struct list
{
	t_nod	*node_a;
	t_nod	*node_b;
	int		dim_a;
	int		dim_b;
}	t_list;

typedef struct tab
{
	t_nod		*location;
	int			size;
	t_pos		position;
	t_nod		*pivot;
	struct tab	*tp;
	struct tab	*tm;
}	t_tab;

int		ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

int		strlen_2(char **argv);
char	**check_param(char **argv, int argc);

t_nod	*add_node(t_nod *node, int value);
t_nod	*free_all_node(t_nod *node);
t_list	*init_list(t_nod *stack, int size);
t_tab	*init_tab(t_nod *location, int size);
t_nod	*init_stack(char **argv);

void	error(void);

int		sort(t_list *l, t_tab *table);

int		rec_sort(t_list *l, t_tab *table);
void	discret(t_list *l);

int		split_a(t_list *l, t_tab *table);
int		split_b(t_list *l, t_tab *table);

int		sa(t_list *l);
int		sb(t_list *l);
int		ss(t_list *l);
int		pa(t_list *l);
int		pb(t_list *l);
int		ra(t_list *l);
int		rb(t_list *l);
int		rr(t_list *l);
int		rra(t_list *l);
int		rrb(t_list *l);
int		rrr(t_list *l);

int		test_i(t_list *stack);
void	printa(t_list *l);
void	print_double_char(char **argv);
void	tester(t_list *l);

#endif