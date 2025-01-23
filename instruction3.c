/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:00:27 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/23 16:48:44 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	sa(t_list *l)
{
	t_nod	*node_tmp;

	node_tmp = l->node_a->next;
	l->node_a->prev->next = l->node_a->next;
	l->node_a->next->prev = l->node_a->prev;
	l->node_a->next->next->prev = l->node_a;
	l->node_a->next = l->node_a->next->next;
	l->node_a->prev = node_tmp;
	node_tmp->next = l->node_a;
	l->node_a = node_tmp;
	reg(l, "sa", SA);
	return (1);
}

int	sb(t_list *l)
{
	t_nod	*node_tmp;

	node_tmp = l->node_b->next;
	l->node_b->prev->next = l->node_b->next;
	l->node_b->next->prev = l->node_b->prev;
	l->node_b->next->next->prev = l->node_b;
	l->node_b->next = l->node_b->next->next;
	l->node_b->prev = node_tmp;
	node_tmp->next = l->node_b;
	l->node_b = node_tmp;
	reg(l, "sb", SB);
	return (1);
}

int	ss(t_list *l)
{
	t_nod	*node_tmp;

	node_tmp = l->node_a->next;
	l->node_a->prev->next = l->node_a->next;
	l->node_a->next->prev = l->node_a->prev;
	l->node_a->next->next->prev = l->node_a;
	l->node_a->next = l->node_a->next->next;
	l->node_a->prev = node_tmp;
	node_tmp->next = l->node_a;
	l->node_a = node_tmp;
	node_tmp = l->node_b->next;
	l->node_b->prev->next = l->node_b->next;
	l->node_b->next->prev = l->node_b->prev;
	l->node_b->next->next->prev = l->node_b;
	l->node_b->next = l->node_b->next->next;
	l->node_b->prev = node_tmp;
	node_tmp->next = l->node_b;
	l->node_b = node_tmp;
	reg(l, "ss", SS);
	return (1);
}
