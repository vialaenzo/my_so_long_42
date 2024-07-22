/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:22:20 by eviala            #+#    #+#             */
/*   Updated: 2024/07/22 11:04:55 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_jump(t_data *data)
{
	int (x) = 1;
	while (data->map_str[x] != '\0')
	{
		if (data->map_str[x - 1] == '\n' && data->map_str[x] == '\n')
			return (ft_error("Error\nJump Line or Col\n"), 0);
		x++;
	}
	return (1);
}

int	ft_check_arg(char **str)
{
	int (i) = 0;
	str = ft_split(str[1], '/');
	if (str == NULL)
		return (ft_error("Error\nSplit error\n"), 0);
	while (str[i] != NULL)
	{
		i++;
	}
	if (ft_count_occ(str[i - 1], '.') != 1
		|| ft_strrchr_str(str[i - 1], ".ber") < 1)
		return (ft_free_split(str), 0);
	ft_free_split(str);
	return (1);
}
