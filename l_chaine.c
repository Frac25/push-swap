#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"push_swap.h"

node	*add_node(node *n, int value)
{
	node	*new_node;

	new_node = malloc(sizeof(node));
	if(new_node == NULL)
		return(NULL);
	new_node->value = value;
	new_node->next = n;
	new_node->prev = NULL;
	if(n != NULL)
		n->prev = new_node;
	return (new_node);
}

list	*init_list(node *n, int arg)
{
	list	*new_list;

	new_list = malloc(sizeof(list));
	if(new_list == NULL)
	return(NULL);

	new_list->node_1 = n;
	new_list->node_2 = n->next;
	return(new_list);
}


void	printn(list *l)
{
	node *n2;
	int	i;

	i = 0;
	n2 = l->node_1;
	while(i <= 10)
	{
		printf("prev : %d     ", (n2->prev)->value);
		printf("value : %d     ", n2->value);
		printf("next : %d\n", (n2->next)->value);
		n2 = n2->next;
		i++;
	}
	printf("\n");
}
