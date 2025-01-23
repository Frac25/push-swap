#include "push_swap.h"



int	print_instr (t_ins *ins)
{
	int	i;
	int	n;

	char *ins_name[12] = {"sup",
	"sa",
	"sb",
	"ss",
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rr",
	"rrb",
	"rrr"};

	i = 0;
	n = 0;
	while(i <= 500)
	{
		if (ins[i] != SUP)
		{
			printf("%s\n", ins_name[ins[i]]);
			n++;
		}
		i++;
	}
//	printf("n2 = %d\n", n);
	return (n);
}

int suppr(t_ins *ins, int i)
{
	ins[i] = SUP;
	ins[i + 1] = SUP;
	return(i);
}

int m_ss(t_ins *ins, int i)
{
	ins[i] = SS;
	ins[i + 1] = SUP;

	return(i);
}

int m_rr(t_ins *ins, int i)
{
	ins[i] = RR;
	ins[i + 1] = SUP;

	return(i);
}

int m_rrr(t_ins *ins, int i)
{
	ins[i] = RRR;
	ins[i + 1] = SUP;

	return(i);
}

void	post_sort(t_ins *ins)
{
	int	i;

	i = 0;
	while(ins[i])
	{
		if ((ins[i] == PA && ins[i + 1] == PB) || (ins[i] == PB && ins[i + 1] == PA))
			suppr(ins ,i);
		else if ((ins[i] == SA && ins[i + 1] == SA) || (ins[i] == SB && ins[i + 1] == SB))
			suppr(ins ,i);
		else if ((ins[i] == SA && ins[i + 1] == SB) || (ins[i] == SB && ins[i + 1] == SA))
			m_ss(ins ,i);
		else if ((ins[i] == RA && ins[i + 1] == RB) || (ins[i] == RB && ins[i + 1] == RA))
			m_rr(ins ,i);
		else if ((ins[i] == RRA && ins[i + 1] == RRB) || (ins[i] == RRB && ins[i + 1] == RRA))
			m_rrr(ins ,i);
		else if ((ins[i] == RRA && ins[i + 1] == RA) || (ins[i] == RA && ins[i + 1] == RRA))
			suppr(ins ,i);
		else if ((ins[i] == RRB && ins[i + 1] == RB) || (ins[i] == RB && ins[i + 1] == RRB))
			suppr(ins ,i);
		i++;
	}
}

