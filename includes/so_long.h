/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:47:56 by eviala            #+#    #+#             */
/*   Updated: 2024/07/22 12:06:13 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAX_CHANGES 100000

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct img_s
{
	void		*img_floor;
	void		*img_player;
	void		*img_exit;
	void		*img_wall;
	void		*img_collect;
	int			height;
	int			width;
	char		*player;
	char		*floor;
	char		*wall;
	char		*collect;
	char		*exit;
}				t_img;

typedef struct s_change
{
	int			x;
	int			y;
	char		new_content;
}				t_change;

// Ajoutez ceci à votre structure t_data

typedef struct cnt_s
{
	char		exit;
	char		collect;
	char		player;
	char		wall;
	char		space;
	int			count_p;
	int			count_e;
	int			count_c;
}				t_cnt;

typedef struct pos_s
{
	int			x;
	int			y;
	int			exit_x;
	int			exit_y;
}				t_pos;

typedef struct data_s
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			width;
	int			height;
	int			fd;
	char		**map;
	char		*map_str;
	t_cnt		content;
	t_img		img;
	t_pos		pos;
	int			count;
	int			change_count;
	t_change	changes[MAX_CHANGES];
}				t_data;

// Initiation

void			init_content(t_cnt *content);
void			init_img(t_data *data);

// Others

char			*convert_map(t_data *data);
int				ft_mult_error(t_data *data);
void			*ft_error(char *str);
void			*ft_free_map(t_data *data);
void			ft_free_split(char **split);

// Map

void			ft_display_map(t_data *data);
char			**map_load(char **str, t_data *data);
char			*map_getter(int fd, t_data *data);
char			**map_checker(int fd, t_data *data);

// Checks

void			ft_find_content(t_data *data);
int				ft_check_arg(char **str);
int				ft_check_line_wall(char *map_line, t_data *data);
int				ft_check_col_wall(char *map_line, t_data *data);
int				ft_check_map_format(t_data *data);
int				ft_check_unknown(t_data *data);
int				ft_check_jump(t_data *data);
int				ft_floodfill(t_data *data);
int				checker_cons(t_data *data);

// Events

int				the_end(t_data *data);
int				which_key(int keysym, t_data *data);
int				check_finish(t_data *data);
void			display_img(t_data *data, void *img, int x, int y);

// Render

void			core_render_game(t_data *data);
void			add_change(t_data *data, int x, int y, char new_content);
void			render_top(t_data *data);
void			render_bot(t_data *data);
void			render_right(t_data *data);
void			render_left(t_data *data);

#endif
