/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:00:19 by eviala            #+#    #+#             */
/*   Updated: 2024/06/24 12:20:07 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_extra(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_extra('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_extra(nb / 10);
		ft_putnbr_extra(nb % 10);
	}
	else
	{
		ft_putchar_extra(nb + '0');
	}
}
