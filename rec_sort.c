/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:04:12 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/24 07:40:47 by sydubois         ###   ########.fr       */
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

void	pivot_2(t_tab *table)
{
	t_nod	*location_t;

	location_t = table->location;

	while (location_t->discret != table->size / 3)
		location_t = location_t->next;
	table->pivot = location_t;
	while (location_t->discret != table->size * 2 / 3)
		location_t = location_t->next;
	table->pivot_2 = location_t;

//	printf("p1 = %d et p2 = %d\n", table->pivot->discret, table->pivot_2->discret);
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

int opti_sort_3(t_list *l, t_tab *table)
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
			n += to_top_a(l, table) + sort_r3(l, table);
		//	printf("TRI : position = %u  size = %d  v = %d  n = %d\n", table->position, table->size, table->location->discret, n);
		return (n);
}

int	rec_sort(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	if (table->size <= 3)
	{
//		n += opti_sort_3(l, table);
		n += to_top_a(l, table) + sort_r3(l, table);
	}
	else
	{
//		printf("SPLIT position = %u  size = %d  v = %d\n", table->position, table->size, table->location->discret);
		table->tm = init_tab(NULL, 0);
		table->tp = init_tab(NULL, 0);
//		table->t3 = init_tab(NULL, 0);
		table->pivot = p_moyen(table);
//		pivot_2(table);

		if (table->position == u_a || table->position == d_a)
			n += split_a(l, table);
		else
			n += split_b(l, table);
		n += rec_sort(l, table->tp);
		n += rec_sort(l, table->tm);
		free(table->tm);
		free(table->tp);
//		free(table->t3);
	}
	return (n);
}
