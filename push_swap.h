//#ifndef PUSH_SWAP_H
//# define PUSH_SWAP_H

typedef struct nod
{
	int			value;
	struct nod	*next;
	struct nod	*prev;
} node;

typedef struct lis
{
	node	*node_1;
	node	*node_2;
	int		dim;
} list;


int	ft_atoi(const char *str);
node	*add_node(node *first_node, int value);
list	*init_list(node *n, int arg);
void	printl_e(list *l1, list *l2);
void	printl_e1(list *l1);
void	printl_a1(list *l1);
void	printl_a2(list *l1, list *l2);
void	printn(list *l);
