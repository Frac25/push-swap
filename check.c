#include"push_swap.h"

int strlen_2(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void check_char(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (i < strlen_2
(str))
	{
		j = 0;
		if (str[i][0] == '+' || str[i][0] == '-')
			j++;
		if (str[i][j] < '0' || str[i][j] > '9')
			error();
		j++;
		while(str[i][j] != '\0')
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				error();
			j++;
		}
		i++;
	}
}

void	check_max(char **str)
{
	int		i;
	int		j;
	int		s;
	long	a;

	i = 0;
	while (i < strlen_2
(str))
	{
		s = 1;
		a = 0;
		j = 0;
		while (str[i][j] == ' ' || (str[i][j] >= 9 && str[i][j] <= 13))
			j++;
		if (str[i][j] == '+' || str[i][j] == '-')
		{
			if (str[i][j] == '-')
				s = -s;
			j++;
		}
		while (str[i][j] >= '0' && str[i][j] <= '9')
			a = a * 10 + str[i][j++] - 48;
		if((s * a) > 2147483647 || (s * a) < -2147483648)
			error();
		i++;
	}
}

void	check_dup(char **str)
{
	int i;
	int j;

	i = 0;
	while (i < strlen_2
(str) -1)
	{
		j = i + 1;
		while (j < strlen_2
	(str))
		{
			if ( ft_atoi(str[i]) == ft_atoi(str[j]))
				error();
			j++;
		}
		i++;
	}
}

char **check_param(char **argv, int argc)
{
	argv = &argv[1];
	if(argc == 2)
	{
		if (!argv[1])
			error();
		argv = ft_split(argv[0], ' ');
	}
	check_char(argv);
	check_max(argv);
	check_dup(argv);
	return(argv);
}
