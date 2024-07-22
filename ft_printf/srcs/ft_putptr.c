/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:48:45 by eviala            #+#    #+#             */
/*   Updated: 2024/06/22 15:45:12 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthex_ptr(unsigned long n, char c)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += puthex_ptr(n / 16, c);
		count += ft_putchar("0123456789abcdef"[n % 16]);
	}
	else
		count += ft_putchar("0123456789abcdef"[n]);
	return (count);
}

int	ft_putptr(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	count += puthex_ptr(n, 'x');
	return (count);
}
