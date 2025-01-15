/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:00:01 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/15 11:00:05 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ra(t_list *l)
{
	l->node_a = l->node_a->next;
	ft_printf("ra\n");
	return (1);
}

int	rb(t_list *l)
{
	l->node_b = l->node_b->next;
	ft_printf("rb\n");
	return (1);
}

int	rr(t_list *l)
{
	l->node_a = l->node_a->next;
	l->node_b = l->node_b->next;
	ft_printf("rr\n");
	return (1);
}
