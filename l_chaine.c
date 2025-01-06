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
	new_node->index = n->index + 1;
	else
	new_node->index = 0;
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

	new_list->node_a = n;
	new_list->node_b = NULL;
	new_list->dim_a = arg;

	return(new_list);
}


void	printa(list *l)
{
	node *na = NULL;
	node *nb = NULL;
	int	i;

	i = 0;
	if(l->node_a != NULL)
		na = l->node_a;
	if(l->node_b != NULL)
		nb = l->node_b;
	while(i <= l->dim_a)
	{
		if(na != NULL)
		{
			printf("ai : %d     ", na->index);
			printf("p : %d     ", (na->prev)->value);
			printf("v : %d     ", na->value);
			printf("n : %d               ", (na->next)->value);
		}
		if(nb != NULL)
		{
			printf("bi : %d     ", nb->index);
			printf("p : %d     ", (nb->prev)->value);
			printf("v : %d     ", nb->value);
			printf("n : %d\n", (nb->next)->value);
		}
		else
			printf("\n");
		if(na != NULL)
			na = na->next;
		if(nb != NULL)
			nb = nb->next;
		i++;
	}

	printf("\n");
}

void	tester(list *l)
{
	node	*nt;
	int		i;
		nt = l->node_a;
	i = 0;
	while(nt != l->node_a->prev)
	{
		if(nt->value < nt->next->value)
			i++;
		else
			printf("tester KO a , i = %d\n", i);
		nt = nt->next;
	}
}
