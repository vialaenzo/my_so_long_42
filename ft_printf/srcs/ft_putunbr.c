/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:27:16 by eviala            #+#    #+#             */
/*   Updated: 2024/06/22 15:45:14 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}
