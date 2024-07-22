/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:33:34 by eviala            #+#    #+#             */
/*   Updated: 2024/07/22 12:36:31 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_content(t_data *data)
{
	int (i) = 0;
	int (y) = 0;
	while (data->map[i])
	{
		while (data->map[i][y])
		{
			if (data->map[i][y] == data->content.collect)
				data->content.count_c++;
			else if (data->map[i][y] == data->content.exit)
				data->content.count_e++;
			else if (data->map[i][y] == data->content.player)
				data->content.count_p++;
			y++;
		}
		y = 0;
		i++;
	}
}

int	ft_check_line_wall(char *map_line, t_data *data)
{
	int (i) = 0;
	while (map_line[i])
	{
		if (map_line[i] != data->content.wall)
			return (ft_error("Error\nMap not close (line)\n"), 0);
		i++;
	}
	return (1);
}

int	ft_check_col_wall(char *map_line, t_data *data)
{
	int (i) = 0;
	while (map_line[i])
		i++;
	if (map_line[0] != data->content.wall || map_line[i - 1]
		!= data->content.wall)
		return (ft_error("Error\nMap not close (column)\n"), 0);
	data->width = i;
	return (1);
}

int	ft_check_map_format(t_data *data)
{
	int (y) = 0;
	int (x) = 0;
	int (count_x) = 0;
	while (data->map[0][count_x])
		count_x++;
	if (count_x > 24)
		return (ft_error("Error\nBad Width <= 12 \n"), 0);
	while (data->map[y] != NULL)
	{
		while (data->map[y][x])
			x++;
		if (x != count_x)
		{
			ft_error("Error\nBad Map Format\n");
			return (0);
		}
		x = 0;
		y++;
	}
	if (y > 12)
	{
		return (ft_error("Error\nBad Height <= 24\n"), 0);
	}
	return (1);
}

int	ft_check_unknown(t_data *data)
{
	int (i) = 0;
	data->map_str = convert_map(data);
	if (data->map_str == NULL)
		return (0);
	while (data->map_str[i])
	{
		if (data->map_str[i] != data->content.wall && data->map_str[i]
			!= data->content.player && data->map_str[i]
			!= data->content.exit
			&& data->map_str[i] != data->content.collect
			&& data->map_str[i] != data->content.space)
		{
			ft_error("Error\nUnknown symbol(s) in map\n");
			return (0);
		}
		i++;
	}
	return (1);
}
