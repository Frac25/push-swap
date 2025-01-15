/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:20:33 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/15 11:27:59 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	split_a(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	while ((table->tp->size + table->tm->size) < table->size)
	{
		if (table->position == d_a)
			n += rra(l);
		if (table->pivot->value <= l->node_a->value)
		{
			n += pb(l);
			table->tp->location = l->node_b;
			table->tp->size++;
		}
		else
		{
			n += pb(l);
			if (table->tm->size == 0)
				table->tm->location = l->node_b;
			n += rb(l);
			table->tm->size++;
		}
	}
	table->tp->position = u_b;
	table->tm->position = d_b;
	return (n);
}

int	split_b(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	while ((table->tp->size + table->tm->size) < table->size)
	{
		if (table->position == d_b)
			n += rrb(l);
		if (table->pivot->value <= l->node_b->value)
		{
			n += pa(l);
			table->tp->location = l->node_a;
			table->tp->size++;
		}
		else
		{
			n += pa(l);
			if (table->tm->size == 0)
				table->tm->location = l->node_a;
			n += ra(l);
			table->tm->size++;
		}
	}
	table->tp->position = u_a;
	table->tm->position = d_a;
	return (n);
}
