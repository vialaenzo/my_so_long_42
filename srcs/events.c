/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:02:34 by eviala            #+#    #+#             */
/*   Updated: 2024/07/22 12:01:14 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	which_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		the_end(data);
	else if (keysym == XK_w)
		render_top(data);
	else if (keysym == XK_d)
		render_right(data);
	else if (keysym == XK_a)
		render_left(data);
	else if (keysym == XK_s)
		render_bot(data);
	return (0);
}

int	the_end(t_data *data)
{
	if (data->map)
		ft_free_map(data);
	if (data->map_str)
	{
		free(data->map_str);
		data->map_str = NULL;
	}
	if (data->mlx_ptr)
	{
		if (data->img.img_wall)
			mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
		if (data->img.img_floor)
			mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
		if (data->img.img_collect)
			mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
		if (data->img.img_player)
			mlx_destroy_image(data->mlx_ptr, data->img.img_player);
		if (data->img.img_exit)
			mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
		if (data->mlx_win)
			mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(0);
}

int	check_finish(t_data *data)
{
	if (data->content.count_c == 0)
	{
		ft_printf("Congrates, you win in : %d moves !\n", data->count);
		the_end(data);
	}
	return (0);
}

void	display_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.width * x, data->img.height * y);
}
