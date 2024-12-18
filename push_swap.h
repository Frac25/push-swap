//#ifndef PUSH_SWAP_H
//# define PUSH_SWAP_H

typedef struct nod
{
	int				value;
	struct nod	*next;
} node;

typedef struct lis
{
	node	*node_1;
	node	*node_2;
	node	*node_m;
	node	*node_n;
} list;

