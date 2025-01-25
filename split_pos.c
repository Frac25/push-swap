/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:20:33 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/25 12:09:07 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	split_ua(t_list *l, t_tab *table)
{
	int	n;
	write(1,"_ua\n", 4);
	n = 0;

	while ((table->t1->size + table->t2->size + table->t3->size) < table->size)
	{
		if (l->node_a->value >= table->pivot_2->value)
		{
			table->t1->location = l->node_a;
			n += pb(l);
			table->t1->size++;
		}
		else if(l->node_a->value >= table->pivot->value)
		{
			if (table->t2->size == 0)
				table->t2->location = l->node_a;
			n += pb(l) + rb(l);
			table->t2->size++;
		}
		else
		{
			if (table->t3->size == 0)
				table->t3->location = l->node_a;
			n += ra(l);
			table->t3->size++;
		}
	}
	table->t1->position = u_b;
	table->t2->position = d_b;
	table->t3->position = d_a;
	return (n);
}

int	split_ub(t_list *l, t_tab *table)
{
	int	n;
	write(1,"_ub\n", 4);
	n = 0;
	while ((table->t1->size + table->t2->size + table->t3->size) < table->size)
	{
		if (l->node_b->value >= table->pivot_2->value)
		{
			table->t1->location = l->node_b;
			n += pa(l);
			table->t1->size++;
		}
		else if(l->node_b->value >= table->pivot->value)
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
	table->t1->position = u_a;
	table->t2->position = d_b;
	table->t3->position = d_a;
	return (n);
}

int	split_db(t_list *l, t_tab *table)
{
	int	n;
	write(1,"_db\n", 4);
	n = 0;
	while ((table->t1->size + table->t2->size + table->t3->size) < table->size)
	{
		n += rrb(l);
		if (l->node_b->value >= table->pivot_2->value)
		{
			table->t1->location = l->node_b;
			n += pa(l);
			table->t1->size++;
		}
		else if(l->node_b->value >= table->pivot->value)
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
	table->t1->position = u_a;
	table->t2->position = u_b;
	table->t3->position = d_a;
	return (n);
}

int	split_da(t_list *l, t_tab *table)
{
	int	n;
	write(1,"_da\n", 4);
	n = 0;
	while ((table->t1->size + table->t2->size + table->t3->size) < table->size)
	{
		n += rra(l);
		if (l->node_a->value >= table->pivot_2->value)
		{
			table->t1->location = l->node_a;
			table->t1->size++;
		}
		else if(l->node_a->value >= table->pivot->value)
		{
			table->t2->location = l->node_a;
			n += pb(l);
			table->t2->size++;
		}
		else
		{
			if (table->t3->size == 0)
				table->t3->location = l->node_a;
			n += pb(l) + rb(l);
			table->t3->size++;
		}
	}
	table->t1->position = u_a;
	table->t2->position = u_b;
	table->t3->position = d_b;
	return (n);
}

int	split_a(t_list *l, t_tab *table)
{
	int	n;
	write(1,"_a\n", 3);
	n = 0;

	while ((table->t1->size + table->t2->size) < table->size)
	{
		if (table->position == d_a)
			n += rra(l);
		if (l->node_a->value >= table->pivot->value)
		{
			n += pb(l);
			table->t1->location = l->node_b;
			table->t1->size++;
		}
		else
		{
			n += pb(l);
			if (table->t2->size == 0)
				table->t2->location = l->node_b;
			n += rb(l);
			table->t2->size++;
		}
	}
	table->t1->position = u_b;
	table->t2->position = d_b;
	return (n);
}

int	split_b(t_list *l, t_tab *table)
{
	int	n;
	write(1,"_b\n", 3);
	n = 0;
	while ((table->t1->size + table->t2->size) < table->size)
	{
		if (table->position == d_b)
			n += rrb(l);
		if (l->node_b->value >= table->pivot->value)
		{
			n += pa(l);
			table->t1->location = l->node_a;
			table->t1->size++;
		}
		else
		{
			n += pa(l);
			if (table->t2->size == 0)
				table->t2->location = l->node_a;
			n += ra(l);
			table->t2->size++;
		}
	}
	table->t1->position = u_a;
	table->t2->position = d_a;
	return (n);
}
