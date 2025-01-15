/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:28:29 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/15 11:31:44 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	test_i(t_list *stack)
{
	printa(stack);
	sa(stack);
	printa(stack);
	sa(stack);
	printa(stack);
	ra(stack);
	printa(stack);
	ra(stack);
	printa(stack);
	rra(stack);
	printa(stack);
	rra(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	pa(stack);
	printa(stack);
	pa(stack);
	printa(stack);
	pa(stack);
	printa(stack);
	pa(stack);
	printa(stack);
	pa(stack);
	printa(stack);
	pa(stack);
	printa(stack);
	pa(stack);
	printa(stack);
	pa(stack);
	printa(stack);
	pa(stack);
	printa(stack);
	pa(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	pb(stack);
	printa(stack);
	ss(stack);
	printa(stack);
	rr(stack);
	printa(stack);
	rra(stack);
	printa(stack);
	rrb(stack);
	printa(stack);
	rrr(stack);
	printa(stack);
	return (0);
}

void	printa(t_list *l)
{
	t_nod	*na;
	t_nod	*nb;
	int		i;

	na = NULL;
	nb = NULL;
	i = 0;
	if (l->node_a != NULL)
		na = l->node_a;
	if (l->node_b != NULL)
		nb = l->node_b;
	while (i <= l->dim_a + 1)
	{
		if (na != NULL)
		{
			printf("ai : %d     ", na->index);
			printf("p : %d     ", na->prev->value);
			printf("v : %d     ", na->value);
			printf("n : %d               ", na->next->value);
			printf("d : %d               ", na->discret);
		}
		if (nb != NULL)
		{
			printf("bi : %d     ", nb->index);
			printf("p : %d     ", (nb->prev)->value);
			printf("v : %d     ", nb->value);
			printf("n : %d\n", (nb->next)->value);
		}
		else
			printf("\n");
		if (na != NULL)
			na = na->next;
		if (nb != NULL)
			nb = nb->next;
		i++;
	}
	printf("\n");
}

void	tester(t_list *l)
{
	t_nod	*nt;
	int		i;

	printa(l);
	nt = l->node_a;
	i = 0;
	while (nt != l->node_a->prev)
	{
		if (nt->value < nt->next->value)
			i++;
		else
			printf("tester KO a , i = %d\n", i);
		nt = nt->next;
	}
	printf("si pas de KO, c'est OK!\n");
}

void	print_double_char(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			printf("argv[%d][%d] = %c\n", i, j, argv[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
}
