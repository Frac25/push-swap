/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:34:45 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/24 10:18:41 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"push_swap.h"

t_nod	*add_node(t_nod *n, int value)
{
	t_nod	*new_node;

	new_node = malloc(sizeof(t_nod));
	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = value;
	new_node->value_init = value;
	new_node->next = n;
	new_node->prev = NULL;
	new_node->discret = 0;
	if (n == NULL)
		new_node->index = 1;
	else
		new_node->index = n->index + 1;
	if (n != NULL)
		n->prev = new_node;
	return (new_node);
}

t_nod	*free_all_node(t_nod *node)
{
	t_nod	*next_node;
	t_nod	*last_node;

	if (node == NULL)
		return (NULL);
	last_node = node->prev;
	while (node != last_node)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	free(node);
	return (NULL);
}

t_nod	*init_stack(char *argv[])
{
	int		i;
	t_nod	*node_a;
	t_nod	*node_a1;
	int		size;

	size = strlen_2(argv);
	node_a = add_node(NULL, ft_atoi(argv[size - 1]));
	if (node_a == NULL)
		error();
	node_a1 = node_a;
	i = size - 2;
	while (i >= 0)
	{
		node_a = add_node(node_a, ft_atoi(argv[i--]));
		if (node_a == NULL)
		{
			free_all_node(node_a1);
			error();
		}
	}
	node_a->prev = node_a1;
	node_a1->next = node_a;
	return (node_a);
}

t_list	*init_list(t_nod *stack, int size)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (new_list == NULL)
	{
		free_all_node(stack);
		free(new_list);
		error();
	}
	new_list->node_a = stack;
	new_list->node_b = NULL;
	new_list->dim_a = size;
	new_list->dim_b = 0;
	new_list->p = 1;
	new_list->i = 0;
	new_list->ins = malloc(sizeof(t_ins) * 100000);

	return (new_list);
}

t_tab	*init_tab(t_nod *location, int size)
{
	t_tab	*new_table;

	new_table = malloc(sizeof(t_tab));
	if (new_table == NULL)
		return (NULL);
	new_table->size = size;
	new_table->location = location;
	new_table->position = u_a;
	new_table->pivot = NULL;
	new_table->tm = NULL;
	new_table->tp = NULL;
	new_table->t1 = NULL;
	new_table->t2 = NULL;
	new_table->t3 = NULL;

	return (new_table);
}
