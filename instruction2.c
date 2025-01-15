/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:00:10 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/15 11:00:17 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	rra(t_list *l)
{
	l->node_a = l->node_a->prev;
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_list *l)
{
	l->node_b = l->node_b->prev;
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_list *l)
{
	l->node_a = l->node_a->prev;
	l->node_b = l->node_b->prev;
	ft_printf("rrr\n");
	return (1);
}
