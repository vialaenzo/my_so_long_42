/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:26:02 by eviala            #+#    #+#             */
/*   Updated: 2024/07/22 12:03:21 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static char	*switch_value(char *map, char *elem)
// {
// 	char	*temp;

// 	temp = ft_strjoin(map, elem);
// 	free(map);
// 	map = temp;
// 	return (map);
// }

static char	*map_getter_extra(char *map, char *line, char *temp)
{
	if (!map)
		map = ft_strdup(line);
	else
	{
		temp = ft_strjoin(map, line);
		free(map);
		map = temp;
	}
	free(line);
	if (map && map[ft_strlen(map) - 1] != '\n')
	{
		temp = ft_strjoin(map, "\n");
		free(map);
		map = temp;
	}
	return (map);
}

char	*map_getter(int fd, t_data *data)
{
	char	*map;
	char	*line;
	char	*temp;

	map = NULL;
	temp = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map = map_getter_extra(map, line, temp);
		if (map == NULL)
			return (NULL);
		line = get_next_line(fd);
	}
	data->map_str = map;
	return (map);
}

char	**map_checker(int fd, t_data *data)
{
	int (i) = 0;
	data->map = ft_split(map_getter(fd, data), '\n');
	if (!data->map)
		return (free(data->map_str), data->map_str = NULL,
			ft_error("Error\nMap is empty\n"));
	ft_find_content(data);
	if ((ft_mult_error(data) == 0))
		return (NULL);
	if (!(ft_check_map_format(data)))
		return (ft_free_map(data));
	if (!(ft_check_line_wall(data->map[0], data)))
		return (ft_free_map(data));
	if (!(ft_check_jump(data)))
		return (ft_free_map(data));
	while (data->map[++i] != NULL)
		if (!(ft_check_col_wall(data->map[i], data)))
			return (ft_free_map(data), NULL);
	if (!(ft_check_unknown(data)))
		return (ft_free_map(data));
	data->height = i;
	if (!(ft_check_line_wall(data->map[i - 1], data)))
		return (ft_free_map(data));
	if (!(ft_floodfill(data)))
		return (ft_free_map(data), ft_error("Error\nInvalid Map FloodFill\n"));
	return (data->map);
}

char	**map_load(char **str, t_data *data)
{
	int	fd;

	fd = 0;
	data->map = NULL;
	data->map_str = NULL;
	if (ft_check_arg(str) == 0)
		return (ft_error("Error\nBad File Format\n"));
	else
	{
		fd = open(str[1], O_RDONLY);
		data->fd = fd;
		if (fd > 0)
		{
			data->map = map_checker(fd, data);
			close(fd);
			if (data->map == NULL)
				return (NULL);
		}
		else
			return (ft_error("Error\nFailed to open file\n"));
	}
	return (data->map);
}
