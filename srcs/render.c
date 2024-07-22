/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:06:40 by eviala            #+#    #+#             */
/*   Updated: 2024/07/22 13:00:13 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_render(t_data *data)
{
	int	x;

	int (y) = -1;
	while (data->map[++y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == data->content.wall)
				display_img(data, data->img.img_wall, x, y);
			else if (data->map[y][x] == data->content.space)
				display_img(data, data->img.img_floor, x, y);
			else if (data->map[y][x] == data->content.collect)
				display_img(data, data->img.img_collect, x, y);
			else if (data->map[y][x] == data->content.player)
			{
				data->pos.x = x * data->img.width;
				data->pos.y = y * data->img.height;
				display_img(data, data->img.img_player, x, y);
			}
			else if (data->map[y][x] == data->content.exit)
				display_img(data, data->img.img_exit, x, y);
			x++;
		}
	}
}

void	add_change(t_data *data, int x, int y, char new_content)
{
	if (data->change_count < MAX_CHANGES)
	{
		data->changes[data->change_count].x = x;
		data->changes[data->change_count].y = y;
		data->changes[data->change_count].new_content = new_content;
		data->change_count++;
	}
}

int	render_changes(t_data *data)
{
	int			i;
	t_change	change;

	i = 0;
	while (i < data->change_count)
	{
		change = data->changes[i];
		if (change.new_content == data->content.wall)
			display_img(data, data->img.img_wall, change.x, change.y);
		else if (change.new_content == data->content.space)
			display_img(data, data->img.img_floor, change.x, change.y);
		else if (change.new_content == data->content.collect)
			display_img(data, data->img.img_collect, change.x, change.y);
		else if (change.new_content == data->content.player)
			display_img(data, data->img.img_player, change.x, change.y);
		else if (change.new_content == data->content.exit)
			display_img(data, data->img.img_exit, change.x, change.y);
		i++;
	}
	data->change_count = 0;
	return (0);
}

int	handle_key(int key, t_data *data)
{
	which_key(key, data);
	render_changes(data);
	return (0);
}

void	core_render_game(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr, (data->width
				* data->img.width), (data->height * data->img.height),
			"My-So_long-42");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	initial_render(data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &handle_key, data);
	mlx_hook(data->mlx_win, 17, 0, &the_end, data);
	mlx_loop(data->mlx_ptr);
}
