/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:53:21 by eviala            #+#    #+#             */
/*   Updated: 2024/07/22 13:51:04 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_top(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (data->map[pos_y - 1][pos_x] == data->content.collect
			&& data->content.count_c > 0)
			data->content.count_c -= 1;
		data->count += 1;
		ft_printf("Count moves : %d\n", data->count);
		if (pos_x == data->pos.exit_x && pos_y - 1 == data->pos.exit_y)
			check_finish(data);
		ft_printf("Count collect : %d\n", data->content.count_c);
		add_change(data, pos_x, pos_y - 1, data->content.player);
		if ((pos_x == data->pos.exit_x) && (pos_y == data->pos.exit_y))
			add_change(data, pos_x, pos_y, data->content.exit);
		else
			add_change(data, pos_x, pos_y, data->content.space);
		data->pos.y -= data->img.width;
	}
}

void	render_right(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (data->map[pos_y][pos_x + 1] == data->content.collect
			&& data->content.count_c > 0)
			data->content.count_c -= 1;
		data->count += 1;
		ft_printf("Count moves : %d\n", data->count);
		if (pos_x + 1 == data->pos.exit_x && pos_y == data->pos.exit_y)
			check_finish(data);
		ft_printf("Count collect : %d\n", data->content.count_c);
		add_change(data, pos_x + 1, pos_y, data->content.player);
		if ((pos_x == data->pos.exit_x) && (pos_y == data->pos.exit_y))
			add_change(data, pos_x, pos_y, data->content.exit);
		else
			add_change(data, pos_x, pos_y, data->content.space);
		data->pos.x += data->img.height;
	}
}

void	render_left(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (data->map[pos_y][pos_x - 1] == data->content.collect
			&& data->content.count_c > 0)
			data->content.count_c -= 1;
		data->count += 1;
		ft_printf("Count moves : %d\n", data->count);
		if (pos_x - 1 == data->pos.exit_x && pos_y == data->pos.exit_y)
			check_finish(data);
		ft_printf("Count collect : %d\n", data->content.count_c);
		add_change(data, pos_x - 1, pos_y, data->content.player);
		if ((pos_x == data->pos.exit_x) && (pos_y == data->pos.exit_y))
			add_change(data, pos_x, pos_y, data->content.exit);
		else
			add_change(data, pos_x, pos_y, data->content.space);
		data->pos.x -= data->img.height;
	}
}

void	render_bot(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (data->map[pos_y + 1][pos_x] == data->content.collect
			&& data->content.count_c > 0)
			data->content.count_c -= 1;
		data->count += 1;
		ft_printf("Count moves : %d\n", data->count);
		if (pos_x == data->pos.exit_x && pos_y + 1 == data->pos.exit_y)
			check_finish(data);
		ft_printf("Count collect : %d\n", data->content.count_c);
		add_change(data, pos_x, pos_y + 1, data->content.player);
		if ((pos_x == data->pos.exit_x) && (pos_y == data->pos.exit_y))
			add_change(data, pos_x, pos_y, data->content.exit);
		else
			add_change(data, pos_x, pos_y, data->content.space);
		data->pos.y += data->img.width;
	}
}
