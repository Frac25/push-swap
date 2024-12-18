#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	a;

	s = 1;
	a = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - 48;
		i++;
	}
	return (s * a);
}

node	*add_node(node *last_node, int value)
{
	node	*new_node;

	new_node = malloc(sizeof(node));
	if(new_node == NULL)
		return(NULL);
	new_node->value = value;
	new_node->next = last_node;
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

void	swap(list *l)
{
	int	tvalue;

	tvalue = l->node_1->value;
	l->node_1->value = l->node_2->value;
	l->node_2->value = tvalue;
}

void	push(node *a, node *b)
{
	node	*n_1;
	node	*n_2;
	int		tvalue;

	n_1 = a;
	n_2 = a->next;

	tvalue = a->value;
	while(n_1->next != NULL)
	{
		n_1->value = n_2->value;
		n_1 = n_2;
		n_2 = n_2->next;
	}
	n_1->value = 0;
}


int	main(int argc, char *argv[])
{
	int		i;
	list	*list_a;
	list	*list_b;
	node	*node_a;
	node	*node_b;

	node_a = add_node(NULL,ft_atoi(argv[argc - 1]));
	node_b = add_node(NULL,0);
	i = argc -2;;
	while (i > 0)
	{
		node_a = add_node(node_a, ft_atoi(argv[i]));
		node_b = add_node(node_b, 0);
		i--;
	}
	list_a = init_list(node_a, argc);
	list_b = init_list(node_b, argc);

	printl_a(list_a, list_b);
	printl_e(list_a, list_b);

	swap(list_a);
	printl_a(list_a, list_b);
/*
	push(node_a, node_b);

	push(node_a, node_b);

*/
	return(0);
}
