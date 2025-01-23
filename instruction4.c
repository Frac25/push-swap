/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:00:27 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/23 16:48:58 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	pa_a_null(t_list *l)
{
	t_nod	*bn1;

	bn1 = l->node_b->next;
	l->node_b->next->prev = l->node_b->prev;
	l->node_b->prev->next = l->node_b->next;
	l->node_a = l->node_b;
	l->node_a->next = l->node_b;
	l->node_a->prev = l->node_b;
	l->node_b = bn1;
}

void	pa_b_null(t_list *l)
{
	t_nod	*a1;

	a1 = l->node_a;
	l->node_a = l->node_b;
	l->node_a->next = a1;
	l->node_a->prev = a1->prev;
	l->node_a->next->prev = l->node_a;
	l->node_a->prev->next = l->node_a;
	l->node_b = NULL;
}

void	pa_std(t_list *l)
{
	t_nod	*a1;
	t_nod	*bn1;

	bn1 = l->node_b->next;
	l->node_b->next->prev = l->node_b->prev;
	l->node_b->prev->next = l->node_b->next;
	a1 = l->node_a;
	l->node_a = l->node_b;
	l->node_a->next = a1;
	l->node_a->prev = a1->prev;
	l->node_a->next->prev = l->node_a;
	l->node_a->prev->next = l->node_a;
	l->node_b = bn1;
}

int	pa(t_list *l)
{
	if (l->node_a == NULL)
		pa_a_null(l);
	else if (l->node_b->next == l->node_b)
		pa_b_null(l);
	else
		pa_std(l);
	l->dim_a++;
	l->dim_b--;
	reg(l, "pa", PA);
	return (1);
}
