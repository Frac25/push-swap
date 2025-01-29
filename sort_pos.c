/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:27:27 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/29 14:28:14 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	discret(t_list *l)
{
	int		j;
	int		rank;
	t_nod	*node_i;
	t_nod	*node_j;

	node_i = l->node_a;
	node_j = l->node_a;
	while (node_i->discret == 0)
	{
		rank = 0;
		j = 0;
		while (j < l->dim_a)
		{
			if (node_i->value >= node_j->value)
				rank++;
			j++;
			node_j = node_j->next;
		}
		node_i->discret = rank;
		node_i = node_i->next;
	}
}

int	sort_ub_r3(t_list *l)
{
	int	n;
	int	a;
	int	b;
	int	c;

	a = l->node_b->value;
	b = l->node_b->next->value;
	c = l->node_b->next->next->value;
	n = 0;
	if (c > b && b > a)
		n += rb(l) + sb(l) + pa(l) + pa(l) + rrb(l) + pa(l);
	else if (b > c && c > a)
		n += rb(l) + pa(l) + pa(l) + rrb(l) + pa(l);
	else if (c > a && a > b)
		n += rb(l) + sb(l) + pa(l) + rrb(l) + pa(l) + pa(l);
	else if (b > a && a > c)
		n += sb(l) + pa(l) + pa(l) + pa(l);
	else if (a > c && c > b)
		n += pa(l) + sb(l) + pa(l) + pa(l);
	else if (a > b && b > c)
		n += pa(l) + pa(l) + pa(l);
	return (n);
}

int	sort_db_r3(t_list *l)
{
	int	n;
	int	a;
	int	b;
	int	c;

	a = l->node_b->prev->prev->prev->value;
	b = l->node_b->prev->prev->value;
	c = l->node_b->prev->value;
	n = 0;
	if (c > b && b > a)
		n += rrb(l) + pa(l) + rrb(l) + pa(l) + rrb(l) + pa(l);
	else if (b > c && c > a)
		n += rrb(l) + rrb(l) + pa(l) + pa(l) + rrb(l) + pa(l);
	else if (c > a && a > b)
		n += rrb(l) + pa(l) + rrb(l) + rrb(l) + pa(l) + pa(l);
	else if (b > a && a > c)
		n += rrb(l) + rrb(l) + pa(l) + rrb(l) + pa(l) + pa(l);
	else if (a > c && c > b)
		n += rrb(l) + rrb(l) + rrb(l) + pa(l) + sb(l) + pa(l) + pa(l);
	else if (a > b && b > c)
		n += rrb(l) + rrb(l) + rrb(l) + pa(l) + pa(l) + pa(l);
	return (n);
}

int	sort_da_r3(t_list *l)
{
	int	n;
	int	a;
	int	b;
	int	c;

	a = l->node_a->prev->prev->prev->value;
	b = l->node_a->prev->prev->value;
	c = l->node_a->prev->value;
	n = 0;
	if (c > b && b > a)
		n += rra(l) + rra(l) + rra(l);
	else if (b > c && c > a)
		n += rra(l) + rra(l) + sa(l) + rra(l);
	else if (c > a && a > b)
		n += rra(l) + rra(l) + rra(l) + sa(l);
	else if (b > a && a > c)
		n += rra(l) + rra(l) + sa(l) + rra(l) + sa(l);
	else if (a > c && c > b)
		n += rra(l) + rra(l) + pb(l) + rra(l) + sa(l) + pa(l);
	else if (a > b && b > c)
		n += rra(l) + pb(l) + rra(l) + rra(l) + sa(l) + pa(l);
	return (n);
}
