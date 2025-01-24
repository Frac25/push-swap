/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:17:24 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/24 07:41:34 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ever_sorted(t_list *l)
{
	t_nod	*nt;
	int		i;

	nt = l->node_a;
	i = 0;
	while (nt != l->node_a->prev)
	{
		if (nt->value < nt->next->value)
			i++;
		else
			return (0);
		nt = nt->next;
	}
	return (1);
}

int	sort_3(t_list *l)
{
	int	n;
	int	a;
	int	b;
	int	c;

	a = l->node_a->value;
	b = l->node_a->next->value;
	c = l->node_a->next->next->value;
	n = 0;
	if (a > b && b > c)
		n += ra(l);
	if (a > b && b > c)
		n += sa(l);
	if (a > b && b < c && a > c)
		n += ra(l);
	if (a > b && b < c && a < c)
		n += sa(l);
	if (a < b && b > c && a > c)
		n += rra(l);
	if (a < b && b > c && a < c)
		n += rra(l);
	if (a < b && b > c && a < c)
		n += sa(l);
	return (n);
}

int	sort_5(t_list *l)
{
	int	n;

	n = 0;
	while (l->dim_a > 3)
	{
		if (l->node_a->discret < 3)
			n += pb(l);
		else
			n += ra(l);
	}
	if (l->node_b->discret < l->node_b->next->discret)
		n += sb(l);
	sort_3(l);
	while (l->dim_b > 0)
		n += pa(l);
	return (n);
}

int	sort_1to5(t_list *l)
{
	int	n;

	n = 0;
	if (l->dim_a == 2 && (l->node_a->value > l->node_a->next->value))
		n += sa(l);
	else if (l->dim_a == 3)
		n += sort_3(l);
	else if (l->dim_a == 4)
	{
		while (l->dim_a > 3)
		{
			if (l->node_a->discret == 1)
				n += pb(l);
			else
				n += ra(l);
		}
		sort_3(l);
		n += pa(l);
	}
	else if (l->dim_a == 5)
		n += sort_5(l);
	return (n);
}

int	sort(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	if (ever_sorted(l) == 1)
		exit(EXIT_SUCCESS);
	discret(l);
//	l->p = 0;
	if (l->dim_a <= 5)
		n = sort_1to5(l);
	else
		n = rec_sort(l, table);
//	post_sort(l->ins);
//	print_instr(l->ins);
	return (n);
}
