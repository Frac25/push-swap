/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:38:54 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/29 15:10:09 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	free_char2(char **c)
{
	int	i;

	if (c == NULL)
		exit(EXIT_SUCCESS);
	i = strlen_2(c) -1;
	while (i >= 0)
		free(c[i--]);
	free(c);
}

int	main(int argc, char *argv[])
{
	int		n;
	t_list	*l;
	t_nod	*stack_a;
	t_tab	*table;
	char	**param;

	n = 0;
	if (argc <= 1)
		return (1);
	param = check_param(argv, argc);
	stack_a = init_stack(param);
	l = init_list(stack_a, strlen_2(param));
	table = init_tab(l->node_a, l->dim_a);
	n = sort(l, table);
//	tester(l);
//	printf("n = %d\n", n);
	free_all_node(stack_a);
	free(l);
	free(table);
	free_char2(param);
	return (0);
}

/*

//	tester(l);
//	printf("n = %d\n", n);


	if (table == NULL)
	{
		free_all_node(stack_a);
		free(l);
		free(table);
		error();
	}
*/
