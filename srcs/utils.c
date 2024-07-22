/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:26:23 by eviala            #+#    #+#             */
/*   Updated: 2024/07/18 12:01:11 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (NULL);
}

void	*ft_free_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}

void	ft_display_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i] != NULL)
	{
		ft_printf("[%d] | %s\n", i, data->map[i]);
		i++;
	}
}

int	ft_mult_error(t_data *data)
{
	if (data->content.count_c == 0)
		return (ft_free_map(data),
			ft_error("Error\nCollectible is missing\n"), 0);
	else if (data->content.count_e < 1)
		return (ft_free_map(data),
			ft_error("Error\nExit is missing\n"), 0);
	else if (data->content.count_e > 1)
		return (ft_free_map(data),
			ft_error("Error\nExit is too many\n"), 0);
	else if (data->content.count_p < 1)
		return (ft_free_map(data),
			ft_error("Error\nPlayer is missing\n"), 0);
	else if (data->content.count_p > 1)
		return (ft_free_map(data),
			ft_error("Error\nPlayer is too many\n"), 0);
	return (1);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
