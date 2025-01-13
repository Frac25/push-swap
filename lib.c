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

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

char	ft_strlast(const char *s)
{
	size_t	i;
	char	c;

	i = 0;
	while (s[i] != '\0')
	{
		c = s[i];
		i++;
	}
	return (c);
}