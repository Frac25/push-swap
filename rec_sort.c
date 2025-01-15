/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:04:12 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/15 17:11:15 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
		{
			n += ra(l);
			n += sa(l);
			n += rra(l);
		}
		if (l->node_a->value > l->node_a->next->value)
			n += sa(l);
	}
	return (n);
}

int	rec_sort(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	if (table->size <= 3)
	{
		n += to_top_a(l, table);
		n += sort_r3(l, table);
	}
	else
	{
		table->tm = init_tab(NULL, 0);
		table->tp = init_tab(NULL, 0);
		table->pivot = p_moyen(table);
		if (table->position == u_a || table->position == d_a)
			n += split_a(l, table);
		else
			n += split_b(l, table);
		n += rec_sort(l, table->tp);
		n += rec_sort(l, table->tm);
		free(table->tm);
		free(table->tp);
	}
	return (n);
}
