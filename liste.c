#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"push_swap.h"

nod	*add_node(nod *n, int value)
{
	nod	*new_node;

	new_node = malloc(sizeof(nod));
	if(new_node == NULL)
	{
		free(new_node);
		return(NULL);
	}
	new_node->value = value;
	new_node->value_init = value;
	new_node->next = n;
	new_node->prev = NULL;
	new_node->discret = 0;

	if(n == NULL)
		new_node->index = 1;
	else
		new_node->index = n->index + 1;
	if(n != NULL)
		n->prev = new_node;
	return (new_node);
}
nod	*free_all_node(nod *node)
{
	nod *next_node;

	if (node == NULL)
		return (NULL);
	while (node != NULL)
	{
		if(node != node->next)
		{
			next_node = node->next;
			free(node);
			node = next_node;
		}
		else
			free(node);
	}
	return(NULL);
}

nod	*init_stack(int argc, char *argv[])
{
	int		i;
	nod	*node_a;
	nod	*node_a1;

	node_a = add_node(NULL,ft_atoi(argv[argc - 1]));
	if(node_a == NULL)
		return(NULL);
	node_a1 = node_a;
	i = argc -2;;
	while (i > 0)
	{
		node_a = add_node(node_a, ft_atoi(argv[i--]));
		if(node_a == NULL)
			return(free_all_node(node_a1));
	}
	node_a->prev = node_a1;
	node_a1->next = node_a;
	return(node_a);
}

list	*init_list(nod *stack, int size)
{
	list	*new_list;

	new_list = malloc(sizeof(list));
	if(new_list == NULL)
		return(NULL);
	new_list->node_a = stack;
	new_list->node_b = NULL;
	new_list->dim_a = size; //verifier
	new_list->dim_b = 0;
	new_list->dis = 0;
	return(new_list);
}

tab	*init_tab(nod *location, int size)
{
	tab		*new_table;

	new_table = malloc(sizeof(tab));
	if(new_table == NULL)
		return(NULL);
	new_table->size = size;
	new_table->location = location;
	new_table->position = u_a;
	new_table->pivot = NULL;
	new_table->tm = NULL;
	new_table->tp = NULL;
	return(new_table);
}
