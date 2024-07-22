/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:29:22 by eviala            #+#    #+#             */
/*   Updated: 2024/06/22 15:45:07 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16, format);
		if (format == 'X')
			count += ft_putchar("0123456789ABCDEF"[n % 16]);
		else
			count += ft_putchar("0123456789abcdef"[n % 16]);
	}
	else
	{
		if (format == 'X')
			count += ft_putchar("0123456789ABCDEF"[n]);
		else
			count += ft_putchar("0123456789abcdef"[n]);
	}
	return (count);
}
