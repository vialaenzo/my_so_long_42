/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:23:00 by eviala            #+#    #+#             */
/*   Updated: 2024/06/14 15:15:35 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_whichprint(const char *str, int *i, va_list args)
{
	int	count;

	count = 0;
	(*i)++;
	if (str[*i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (str[*i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (str[*i] == 'd' || str[*i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (str[*i] == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (str[*i] == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 'x');
	else if (str[*i] == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 'X');
	else if (str[*i] == 'p')
		count += ft_putptr(va_arg(args, unsigned long));
	else if (str[*i] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_whichprint(str, &i, args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
