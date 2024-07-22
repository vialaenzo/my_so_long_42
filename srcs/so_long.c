/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:04:41 by eviala            #+#    #+#             */
/*   Updated: 2024/07/22 12:09:13 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_error("Error\n .ber argument is required\n");
		return (0);
	}
	data.mlx_ptr = NULL;
	data.count = 0;
	init_content(&(data.content));
	data.map = map_load(argv, &data);
	if (data.map != NULL)
	{
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
			return (ft_error("Error\nmlx_ptr is NULL\n"), the_end(&data));
		init_img(&data);
		core_render_game(&data);
	}
	the_end(&data);
	return (0);
}
