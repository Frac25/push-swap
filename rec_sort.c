/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:04:12 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/29 14:26:52 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	opti_sort_3(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	if (table->position == u_b && table->size == 3)
		n += sort_ub_r3(l);
	else if (table->position == d_b && table->size == 3)
		n += sort_db_r3(l);
	else if (table->position == d_a && table->size == 3)
		n += sort_da_r3(l);
	else
		n += sort_r3(l, table);
	return (n);
}

int	opti_sort_2(t_list *l, t_tab *table)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (table->position == d_a)
	{
		while (i++ < table->size)
			n += rra(l);
	}
	if (table->position == d_b)
	{
		while (i++ < table->size)
			n += rrb(l) + pa(l);
	}
	if (table->position == u_b)
	{
		while (i++ < table->size)
			n += pa(l);
	}
	if (table->size == 2 && (l->node_a->value > l->node_a->next->value))
			n += sa(l);
	return (n);
}

void	pivot_2(t_tab *table)
{
	t_nod	*location_t;
	int		i;
	int		min;

	i = 0;
	location_t = table->location;
	min = location_t->discret;
	while (i < table->size)
	{
		if (min > location_t->discret)
			min = location_t->discret;
		location_t = location_t->next;
		i++;
	}
	location_t = table->location;
	while (location_t->discret != min + table->size / 3)
		location_t = location_t->next;
	table->pivot = location_t;
	while (location_t->discret != min + table->size * 2 / 3)
		location_t = location_t->next;
	table->pivot_2 = location_t;
}

int	split(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	if (table->position == u_a)
		n += split_ua(l, table);
	else if (table->position == u_b)
		n += split_ub(l, table);
	else if (table->position == d_b)
		n += split_db(l, table);
	else if (table->position == d_a)
		n += split_da(l, table);
	return (n);
}

int	rec_sort3(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	if (table->size <= 2)
		n += opti_sort_2(l, table);
	else if (table->size <= 3)
		n += opti_sort_3(l, table);
	else
	{
		table->t1 = init_tab(NULL, 0);
		table->t2 = init_tab(NULL, 0);
		table->t3 = init_tab(NULL, 0);
		pivot_2(table);
		n += split(l, table);
		n += rec_sort3(l, table->t1);
		n += rec_sort3(l, table->t2);
		n += rec_sort3(l, table->t3);
		free(table->t1);
		free(table->t2);
		free(table->t3);
	}
	return (n);
}
