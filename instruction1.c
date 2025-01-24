/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:00:01 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/24 08:18:23 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void reg(t_list *l, char *c, t_ins ins)
{
	if(l->p == 1)
	{
		ft_printf("%s\n", c);
	}
	else if(l->p == 0)
		l->ins[l->i++] = ins;
}

int	ra(t_list *l)
{
	l->node_a = l->node_a->next;
	reg(l, "ra", RA);
	return (1);
}

int	rb(t_list *l)
{
	l->node_b = l->node_b->next;
	reg(l, "rb", RB);
	return (1);
}

int	rr(t_list *l)
{
	l->node_a = l->node_a->next;
	l->node_b = l->node_b->next;
	reg(l, "rr", RR);
	return (1);
}
