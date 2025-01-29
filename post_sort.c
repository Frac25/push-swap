/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:15:23 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/29 14:16:32 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (i <= 500)
	{
		if (ins[i] != SUP)
		{
			printf("%s\n", ins_name[ins[i]]);
			n++;
		}
		i++;
	}
	return (n);
}

int	suppr(t_ins *ins, int i)
{
	ins[i] = SUP;
	ins[i + 1] = SUP;
	return (i);
}

int	m_ss(t_ins *ins, int i)
{
	ins[i] = SS;
	ins[i + 1] = SUP;
	return (i);
}

int	m_rr(t_ins *ins, int i)
{
	ins[i] = RR;
	ins[i + 1] = SUP;
	return (i);
}

int	m_rrr(t_ins *ins, int i)
{
	ins[i] = RRR;
	ins[i + 1] = SUP;
	return (i);
}

void	post_sort(t_list *l)
{
	int		i;
	t_ins	*tab;

	l->ins = malloc(sizeof(t_ins) * 100000); // a refaire
	tab = l->ins;
	i = 0;
	while (tab[i])
	{
		if ((tab[i] == PA && tab[i + 1] == PB) || (tab[i] == PB && tab[i + 1] == PA))
			suppr(tab, i);
		else if ((tab[i] == SA && tab[i + 1] == SA) || (tab[i] == SB && tab[i + 1] == SB))
			suppr(tab, i);
		else if ((tab[i] == SA && tab[i + 1] == SB) || (tab[i] == SB && tab[i + 1] == SA))
			m_ss(tab, i);
		else if ((tab[i] == RA && tab[i + 1] == RB) || (tab[i] == RB && tab[i + 1] == RA))
			m_rr(tab, i);
		else if ((tab[i] == RRA && tab[i + 1] == RRB) || (tab[i] == RRB && tab[i + 1] == RRA))
			m_rrr(tab, i);
		else if ((tab[i] == RRA && tab[i + 1] == RA) || (tab[i] == RA && tab[i + 1] == RRA))
			suppr(tab, i);
		else if ((tab[i] == RRB && tab[i + 1] == RB) || (tab[i] == RB && tab[i + 1] == RRB))
			suppr(tab, i);
		i++;
	}
}
