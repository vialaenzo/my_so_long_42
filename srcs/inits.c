/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:49:03 by eviala            #+#    #+#             */
/*   Updated: 2024/07/22 12:14:27 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_content(t_cnt *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->space = '0';
	content->collect = 'C';
	content->count_p = 0;
	content->count_e = 0;
	content->count_c = 0;
}

void	init_img(t_data *data)
{
	data->change_count = 0;
	data->img.height = 80;
	data->img.width = 80;
	data->img.floor = "./tsrcs/floor_texture.xpm";
	data->img.wall = "./tsrcs/wall_texture.xpm";
	data->img.collect = "./tsrcs/collect.xpm";
	data->img.player = "./tsrcs/mario_player.xpm";
	data->img.exit = "./tsrcs/exit_texture.xpm";
	data->mlx_win = NULL;
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
			&(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	if (!(data->img.img_wall) || !(data->img.img_floor) || !(data->img.img_exit)
		|| !(data->img.img_collect) || !(data->img.img_player))
	{
		ft_printf("Error\nTexture not found\n");
		the_end(data);
	}
}
