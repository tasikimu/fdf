/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 12:56:14 by tasikimu          #+#    #+#             */
/*   Updated: 2018/08/10 15:13:19 by tasikimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>

# define PADDING_X		700
# define PADDING_Y		200
# define WINDOW_SIZE_X	1920
# define WINDOW_SIZE_Y	1080
# define RD				0xEC354C
# define GRN			    0x25FF50
# define ESC 			53
# define A				0
# define S				12
# define D 				2
# define F				3
# define G				5
# define H 				4
# define Q 				12
# define E 				14
# define C 				8
# define Z	 			6
# define R	 			15
# define W  			126
# define TAB 			15
# define F 				3
# define T 				17
# define Y 				16
# define H 				4
# define G   			5

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_env
{
	char				*file_name;
	int					*tab_width;
	int					fd;
	int					height;
	int					width;
	int					depth;
	int					error;
	t_point				view;
	t_point				rot;
	t_point				**point;
	t_point				**coord;
	t_list				*list;
	int					**height_tile;
}						t_env;

typedef struct			s_mlx
{
	double				height;
	double				width;
	void				*mlx;
	void				*window;
}						t_mlx;

typedef struct			s_delta
{
	int					x;
	int					y;
	int					abs_x;
	int					abs_y;
}						t_delta;

typedef struct			s_data
{
	t_env *env;
	t_mlx *mlx;
}						t_data;

t_env					*recover_env(void);
t_mlx					*init_mlx(void);
void					init_env(void);
void					init_delta(t_delta *delta, t_point start, t_point end);

void					print_x(t_delta delta, t_mlx *mlx,
		double posx, double pos);
void					print_y(t_delta delta, t_mlx *mlx,
		double posx, double posy);
void					print_line(t_mlx *mlx, t_point start, t_point end);
void					print_horizontal_lines(t_mlx *mlx, t_env *env);
void					print_vertical_lines(t_mlx *mlx, t_env *env);
void					parse(t_env *env);
void					get_width_height_map(t_env *env);
void					read_file(t_env *env);
int						key_hooks(int keycode, t_data *data);
void					reload_fdf(t_mlx *mlx, t_env *env);
void					launch_fdf(t_mlx *mlx, t_env *env);
void					depth(t_mlx *mlx, t_env *env, int keycode);
void					zoom(t_mlx *mlx, t_env *env, int keycode);
void					normal_mod(t_mlx *mlx, t_env *env, int keycode);
void					rot(t_mlx *mlx, t_env *env, int keycode);
void					l_r_up_down(t_mlx *mlx, t_env *env, int keycode);
#endif
