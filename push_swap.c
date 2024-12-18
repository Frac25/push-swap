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

node	*creat(int value)
{
	node	*new_node;

	new_node = malloc(sizeof(node));
	if(new_node == NULL)
		return(NULL);
	new_node->index = 1;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

node	*add(node *last_node, int value)
{
	node	*new_node;

	new_node = malloc(sizeof(node));
	if(new_node == NULL)
		return(NULL);
	new_node->index = last_node->index + 1;
	new_node->value = value;
	new_node->next = last_node;
	return (new_node);
}

void	printl(node *l)
{
	node *l2;

	l2 = l;
	while(l2 != NULL)
	{
		printf("index : %d     ", l2->index);
		printf("value : %d     ", l2->value);
		printf("next : %p\n", l2->next);
		l2 = l2->next;
	}
}

void	printlv(node *l)
{
	node *l2;

	l2 = l;
	while(l2 != NULL)
	{
		printf("%d ", l2->value);
		l2 = l2->next;
	}
	printf("\n");
}

void	printn(node *l)
{
	printf("%d ", l->value);
}

void	swap(node *n)
{
	node	*n_next;
	int		tvalue;

	n_next = n->next;
	tvalue = n->value;

	n->value = n_next->value;
	n_next->value = tvalue;
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
	node	*stack_a;
	node	*stack_b;

	stack_a = creat(ft_atoi(argv[argc - 1]));
	stack_b = creat(0);
	i = argc -2;;
	while (i > 0)
	{
		stack_a = add(stack_a, ft_atoi(argv[i]));
		stack_b = add(stack_b, 0);
		i--;
	}
	printlv(stack_a);
	printlv(stack_b);
	printf("\n");

//	swap(stack_a);
	printlv(stack_a);
	printlv(stack_b);
	printf("\n");

	push(stack_a, stack_b);
	printlv(stack_a);
	printlv(stack_b);
	printf("\n");

	push(stack_a, stack_b);
	printlv(stack_a);
	printlv(stack_b);
	printf("\n");

	push(stack_a, stack_b);
	printlv(stack_a);
	printlv(stack_b);
	printf("\n");

	push(stack_b, stack_a);
	printlv(stack_a);
	printlv(stack_b);
	printf("\n");

	push(stack_b, stack_a);
	printlv(stack_a);
	printlv(stack_b);
	printf("\n");

	return(0);
}
