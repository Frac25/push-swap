/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pos2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:20:33 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/29 15:01:04 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	t1_pa(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	table->t1->location = l->node_b;
	n += pa(l);
	table->t1->size++;
	table->t1->position = u_a;
	return (n);
}

int	t3_pb_rb(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	if (table->t3->size == 0)
		table->t3->location = l->node_a;
	n += pb(l) + rb(l);
	table->t3->size++;
	return (n);
}

int	t3_ra(t_list *l, t_tab *table)
{
	int	n;

	n = 0;
	if (table->t3->size == 0)
		table->t3->location = l->node_a;
	n += ra(l);
	table->t3->size++;
	return (n);
}
