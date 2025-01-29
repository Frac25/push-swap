/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_sort_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:17:41 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/29 14:18:43 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nod	*p_moyen(t_tab *table)
{
	int		i;
	int		somme_p;
	int		valeur_p;
	t_nod	*location_t;

	i = 0;
	somme_p = 0;
	location_t = table->location;
	while (i < table->size)
	{
		somme_p += location_t->discret;
		location_t = location_t->next;
		i++;
	}
	valeur_p = (somme_p / i);
	location_t = table->location;
	while (location_t->discret != valeur_p)
		location_t = location_t->next;
	return (location_t);
}

int	split_a(t_list *l, t_tab *table)
{
	int	n;

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

int	to_top_a(t_list *l, t_tab *table)
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
		{
			n += rrb(l);
			n += pa(l);
		}
	}
	if (table->position == u_b)
	{
		while (i++ < table->size)
			n += pa(l);
	}
	return (n);
}

int	sort_r3(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	if (table->size >= 2 && (l->node_a->value > l->node_a->next->value))
			n += sa(l);
	if (table->size == 3)
	{
		if (l->node_a->next->value > l->node_a->next->next->value)
			n += ra(l) + sa(l) + rra(l);
		if (l->node_a->value > l->node_a->next->value)
			n += sa(l);
	}
	return (n);
}

int	rec_sort2(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	if (table->size <= 3)
		n += to_top_a(l, table) + sort_r3(l, table);
	else
	{
		table->t1 = init_tab(NULL, 0);
		table->t2 = init_tab(NULL, 0);
		table->pivot = p_moyen(table);
		if (table->position == u_a || table->position == d_a)
			n += split_a(l, table);
		else
			n += split_b(l, table);
		n += rec_sort2(l, table->t1);
		n += rec_sort2(l, table->t2);
		free(table->t1);
		free(table->t2);
	}
	return (n);
}
