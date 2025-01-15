/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:00:27 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/15 12:08:58 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	pb_b_null(t_list *l)
{
	t_nod	*an1;

	an1 = l->node_a->next;
	l->node_a->next->prev = l->node_a->prev;
	l->node_a->prev->next = l->node_a->next;
	l->node_b = l->node_a;
	l->node_b->next = l->node_a;
	l->node_b->prev = l->node_a;
	l->node_a = an1;
}

void	pb_a_null(t_list *l)
{
	t_nod	*b1;

	b1 = l->node_b;
	l->node_b = l->node_a;
	l->node_b->next = b1;
	l->node_b->prev = b1->prev;
	l->node_b->next->prev = l->node_b;
	l->node_b->prev->next = l->node_b;
	l->node_a = NULL;
}

void	pb_std(t_list *l)
{
	t_nod	*b1;
	t_nod	*an1;

	an1 = l->node_a->next;
	l->node_a->next->prev = l->node_a->prev;
	l->node_a->prev->next = l->node_a->next;
	b1 = l->node_b;
	l->node_b = l->node_a;
	l->node_b->next = b1;
	l->node_b->prev = b1->prev;
	l->node_b->next->prev = l->node_b;
	l->node_b->prev->next = l->node_b;
	l->node_a = an1;
}

int	pb(t_list *l)
{
	if (l->node_b == NULL)
		pb_b_null(l);
	else if (l->node_a->next == l->node_a)
		pb_a_null(l);
	else
		pb_std(l);
	l->dim_a--;
	l->dim_b++;
	ft_printf("pb\n");
	return (1);
}
