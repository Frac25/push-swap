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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*c;
	size_t		i;
	size_t		j;

	if (s1 && s2)
	{
		c = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (c == NULL)
			return (NULL);
		i = 0;
		while (i < ft_strlen(s1))
		{
			c[i] = s1[i];
			i++;
		}
		j = 0;
		while (j < ft_strlen(s2))
			c[i++] = s2[j++];
		c[i] = '\0';
		return (c);
	}
	return (NULL);
}
