#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"push_swap.h"

void	insert(list **head, int value)
{
	list	**newlist;
	static int i = 0;

	new_node = malloc(sizeof(list));
	if(new_node = NULL)
		return(NULL);
	new_node->index = i++;
	new_node->value = value;
	new_node->next = *head;
}

int	main(int argc, char *argv[])
{
	int	i;
	struct list stack_a;

	i = 1;
	printf("argc = %d\n", argc);
	while (i < argc)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}




	return(0);
}