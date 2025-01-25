/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:04:12 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/25 12:14:47 by sydubois         ###   ########.fr       */
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

int	to_top_a(t_list *l, t_tab *table)
{
	int	i;
	int	n;

write(1, "to_top_a\n", 9);
	i = 0;
	n = 0;
	if (table->position == d_a)
	{
		while (i++ < table->size)
			n += rra(l);
	}
	if (table->position == d_b)
	{
		printf("db size = %d\n", table->size );
		while (i++ < table->size)
		{
			n += rrb(l);
			n += pa(l);
			printf("db i= %d\n", i);
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
write(1, "sort_3\n", 7);
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

void	pivot_2(t_tab *table)
{
	t_nod	*location_t;
	int	i;
	int		min;

	i = 0;
	location_t = table->location;
	min = location_t->discret;
	while (i < table->size)
	{
		if(min > location_t->discret)
			min = location_t->discret;
		location_t = location_t->next;
		i++;
	}

	i  = table->size;
	printf("i = %d\n", i);

	location_t = table->location;
	while (location_t->discret != min + table->size / 3 ) //attention -1
	{
		location_t = location_t->next;
//		printf("v2 = %d\n",location_t->next->discret);
//		i  = table->size * 2 / 3;
//		printf("i = %d\n", i);
	}
	table->pivot = location_t;
	while (location_t->discret != min + table->size * 2 / 3 ) //attention -1
	{
		location_t = location_t->next;
//		printf("v2 = %d\n",location_t->next->discret);
//		i  = table->size * 2 / 3;
//		printf("i = %d\n", i);
	}
	table->pivot_2 = location_t;

	printf("p1 = %d et p2 = %d\n", table->pivot->discret, table->pivot_2->discret);
}

int	rec_sort(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	if (table->size <= 3)
		//n += to_top_a(l, table) + sort_r3(l, table);
		n += opti_sort_3(l, table);
	else
		n += rec_sort3(l, table);
	return (n);
}

int	rec_sort2(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	if (table->size <= 3)
		n += to_top_a(l, table) + sort_r3(l, table);
		//		n += opti_sort_3(l, table);
	else
	{
//		printf("SPLIT position = %u  size = %d  v = %d\n", table->position, table->size, table->location->discret);
		table->t1 = init_tab(NULL, 0);
		table->t2 = init_tab(NULL, 0);
		table->pivot = p_moyen(table);
		if (table->position == u_a || table->position == d_a)
			n += split_a(l, table);
		else
			n += split_b(l, table);

		n += rec_sort(l, table->t1);
		n += rec_sort(l, table->t2);
		free(table->t1);
		free(table->t2);
	}
	return (n);
}

int	rec_sort3(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
//	printf("SPLIT position = %u  size = %d  v = %d\n", table->position, table->size, table->location->discret);
	table->t1 = init_tab(NULL, 0);
	table->t2 = init_tab(NULL, 0);
	table->t3 = init_tab(NULL, 0);
//	table->pivot = p_moyen(table);
	pivot_2(table);
	if (table->position == u_a)
		n += split_ua(l, table);
	else if (table->position == u_b)
		n += split_ub(l, table);
	else if (table->position == d_b)
		n += split_db(l, table);
	else if (table->position == d_a)
		n += split_da(l, table);

	n += rec_sort(l, table->t1);
	n += rec_sort(l, table->t2);
	n += rec_sort(l, table->t3);

	free(table->t1);
	free(table->t2);
	free(table->t3);
	return (n);
}
