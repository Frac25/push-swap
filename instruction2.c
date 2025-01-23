/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:00:10 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/23 16:48:31 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	rra(t_list *l)
{
	l->node_a = l->node_a->prev;
	reg(l, "rra", RRA);
	return (1);
}

int	rrb(t_list *l)
{
	l->node_b = l->node_b->prev;
	reg(l, "rrb", RRB);
	return (1);
}

int	rrr(t_list *l)
{
	l->node_a = l->node_a->prev;
	l->node_b = l->node_b->prev;
	reg(l, "rrr", RRR);
	return (1);
}
