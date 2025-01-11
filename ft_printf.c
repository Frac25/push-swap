/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42Lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:50:32 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/11 16:39:38 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putptr(unsigned long n)
{
	int	i;

	write (1, "0", 1);
	write (1, "x", 1);
	i = 2 + ft_putbase(n, "0123456789abcdef", 0);
	return (i);
}

int	ft_print_type(va_list args, char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(args, int));
	if (format == 'i')
		i += ft_putnbr(va_arg(args, int), 0);
	if (format == 's')
		i += ft_putstr(va_arg(args, char *));
	if (format == 'p')
		i += ft_putptr((unsigned long)va_arg(args, char *));
	if (format == 'x')
		i += ft_putbase_ui(va_arg(args, int), "0123456789abcdef", 0);
	if (format == 'X')
		i += ft_putbase_ui(va_arg(args, int), "0123456789ABCDEF", 0);
	if (format == 'd')
		i += ft_putnbr(va_arg(args, int), 0);
	if (format == 'u')
		i += ft_putnbr_ui((unsigned int)va_arg(args, unsigned int), 0);
	if (format == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	char		sep;
	size_t		i;
	int			j;
	va_list		args;

	va_start(args, str);
	sep = '%';
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == sep)
		{
			i++;
			j += ft_print_type(args, str[i]);
		}
		else
			j += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (j);
}
