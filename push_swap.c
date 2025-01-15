/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:38:54 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/15 12:13:42 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int		n;
	t_list	*l;
	t_nod	*stack_a;
	t_tab	*table;

	if (argc <= 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	argv = check_param(argv, argc);
	argc = strlen_2(argv);
	stack_a = init_stack(argv, argc);
	l = init_list(stack_a, argc);
	if (l == NULL)
	{
		free_all_node(stack_a);
		error();
	}
	table = init_tab(l->node_a, argc);
	if (table == NULL)
	{
		free_all_node(stack_a);
		free(l);
		error();
	}
	n = sort(l, table);
	return (1);
}

/*
	tester(l);
	printf("n = %d\n", n);
*/