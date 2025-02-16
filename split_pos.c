/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:20:33 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/29 15:07:50 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	split_ua(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	while ((table->t1->size + table->t2->size + table->t3->size) < table->size)
	{
		if (l->node_a->value >= table->pivot_2->value)
		{
			table->t1->location = l->node_a;
			n += pb(l);
			table->t1->size++;
		}
		else if (l->node_a->value >= table->pivot->value)
		{
			if (table->t2->size == 0)
				table->t2->location = l->node_a;
			n += pb(l) + rb(l);
			table->t2->size++;
		}
		else
			n += t3_ra(l, table);
	}
	table->t1->position = u_b;
	table->t2->position = d_b;
	table->t3->position = d_a;
	return (n);
}

int	split_ub(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	while ((table->t1->size + table->t2->size + table->t3->size) < table->size)
	{
		if (l->node_b->value >= table->pivot_2->value)
			n += t1_pa(l, table);
		else if (l->node_b->value >= table->pivot->value)
		{
			if (table->t2->size == 0)
				table->t2->location = l->node_b;
			n += rb(l);
			table->t2->size++;
		}
		else
		{
			if (table->t3->size == 0)
				table->t3->location = l->node_b;
			n += pa(l) + ra(l);
			table->t3->size++;
		}
	}
	table->t2->position = d_b;
	table->t3->position = d_a;
	return (n);
}

int	split_db(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	while ((table->t1->size + table->t2->size + table->t3->size) < table->size)
	{
		n += rrb(l);
		if (l->node_b->value >= table->pivot_2->value)
			n += t1_pa(l, table);
		else if (l->node_b->value >= table->pivot->value)
		{
			table->t2->location = l->node_b;
			table->t2->size++;
		}
		else
		{
			if (table->t3->size == 0)
				table->t3->location = l->node_b;
			n += pa(l) + ra(l);
			table->t3->size++;
		}
	}
	table->t2->position = u_b;
	table->t3->position = d_a;
	return (n);
}

int	split_da(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	while ((table->t1->size + table->t2->size + table->t3->size) < table->size)
	{
		n += rra(l);
		if (l->node_a->value >= table->pivot_2->value)
		{
			table->t1->location = l->node_a;
			table->t1->size++;
		}
		else if (l->node_a->value >= table->pivot->value)
		{
			table->t2->location = l->node_a;
			n += pb(l);
			table->t2->size++;
		}
		else
			n += t3_pb_rb(l, table);
	}
	table->t1->position = u_a;
	table->t2->position = u_b;
	table->t3->position = d_b;
	return (n);
}
