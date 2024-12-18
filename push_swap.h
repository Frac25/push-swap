//#ifndef PUSH_SWAP_H
//# define PUSH_SWAP_H

typedef struct nod
{
	int				index;
	int				value;
	struct nod	*next;
} node;

typedef struct lis
{
	node	*head;
	node	*tail;
} list;

node	*creat(int value);
node	*add(node *last_node, int value);
void	printl(node *l);
void	printlv(node *l);
int		ft_atoi(const char *str);
