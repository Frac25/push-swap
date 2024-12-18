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
	return (new_node);
}

list	*init_list(node *n, int arg)
{
	int	i;
	list	*new_list;
	node	*n2;

	new_list = malloc(sizeof(list));
	if(new_list == NULL)
	return(NULL);
	i = 0;
	n2 = n;
	while (n2->next != NULL)
	{
		i++;
		if(i == 1)
			new_list->node_1 = n2;
		if(i == 2)
			new_list->node_2 = n2;
		if(i == arg -2)
			new_list->node_m = n2;
		if(i == arg -2)
			new_list->node_n = n2->next; //a revoir
		n2 = n2->next;
	}
	return(new_list);
}

void	printn(node *l)
{
	node *l2;

	l2 = l;
	while(l2 != NULL)
	{
		printf("value : %d     ", l2->value);
		printf("next : %p\n", l2->next);
		l2 = l2->next;
	}
}


void	printl_e(list *l1, list *l2)
{
	printf("1:%d  2:%d  m:%d  n:%d\n", (l1->node_1)->value, (l1->node_2)->value,
	(l1->node_m)->value, (l1->node_n)->value);
	printf("1:%d  2:%d  m:%d  n:%d\n\n", (l2->node_1)->value, (l2->node_2)->value,
	(l2->node_m)->value, (l2->node_n)->value);
}

void	printl_a(list *l1, list *l2)
{
	node	*l10;
	node	*l20;

	l10 = l1->node_1; // a revoir
	l20 = l2->node_1; // a revoir
	while(l10 != NULL)
	{
		printf("%d ", l10->value);
		l10 = l10->next;
	}
	printf("\n");
		while(l20 != NULL)
	{
		printf("%d ", l20->value);
		l20 = l20->next;
	}
	printf("\n\n");
}
