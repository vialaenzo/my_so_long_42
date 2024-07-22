/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:56:26 by eviala            #+#    #+#             */
/*   Updated: 2024/07/20 15:05:53 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_flood
{
	char	*temp_map;
	t_data	*data;
	int		collectibles;
	int		exit_found;
}			t_flood;

char	*convert_map(t_data *data)
{
	char	**temp_map;
	char	*result;
	char	*temp;

	int (i) = 0;
	if (!data || !data->map_str)
		return (NULL);
	temp_map = ft_split(data->map_str, '\n');
	if (!temp_map)
		return (NULL);
	result = ft_strdup("");
	if (!result)
		return (ft_free_split(temp_map), NULL);
	while (temp_map[i])
	{
		temp = ft_strjoin(result, temp_map[i]);
		free(result);
		if (!temp)
			return (ft_free_split(temp_map), NULL);
		result = temp;
		i++;
	}
	ft_free_split(temp_map);
	free(data->map_str);
	return (data->map_str = result, data->map_str);
}

static void	flood_fill(t_flood *flood, int pos, t_data *data)
{
	char	current;

	if (pos < 0 || pos >= (int)ft_strlen(flood->temp_map)
		|| flood->temp_map[pos] == flood->data->content.wall
		|| flood->temp_map[pos] == 'V')
		return ;
	current = flood->temp_map[pos];
	flood->temp_map[pos] = 'V';
	if (current == flood->data->content.collect)
		flood->collectibles++;
	else if (current == flood->data->content.exit)
	{
		flood->exit_found = 1;
		data->pos.exit_x = pos % flood->data->width;
		data->pos.exit_y = pos / flood->data->width;
	}
	flood_fill(flood, pos + 1, data);
	flood_fill(flood, pos - 1, data);
	flood_fill(flood, pos + flood->data->width, data);
	flood_fill(flood, pos - flood->data->width, data);
}

int	ft_floodfill(t_data *data)
{
	t_flood	flood;
	int		player_pos;

	flood.data = data;
	flood.collectibles = 0;
	flood.exit_found = 0;
	flood.temp_map = ft_strdup(data->map_str);
	if (!flood.temp_map)
		return (0);
	player_pos = ft_strchr(flood.temp_map, data->content.player)
		- flood.temp_map;
	if (player_pos >= 0 && player_pos < (int)ft_strlen(flood.temp_map))
		flood_fill(&flood, player_pos, data);
	free(flood.temp_map);
	return (flood.collectibles == data->content.count_c && flood.exit_found);
}
