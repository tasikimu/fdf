/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 10:50:00 by tasikimu          #+#    #+#             */
/*   Updated: 2018/07/26 12:55:13 by tasikimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		key_hooks(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		write(1, "window exited\n", 14);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 126 || keycode == 123
			|| keycode == 125 || keycode == 124)
		l_r_up_down(data->mlx, data->env, keycode);
	else if (keycode == 115 || keycode == 119)
		depth(data->mlx, data->env, keycode);
	else if (keycode == 78 || keycode == 69)
		zoom(data->mlx, data->env, keycode);
	else if (keycode == 12 || keycode == 14)
		rot(data->mlx, data->env, keycode);
	else if (keycode == 15)
		normal_mod(data->mlx, data->env, keycode);
	return (0);
}

void	reload_fdf(t_mlx *mlx, t_env *env)
{
	mlx_clear_window(mlx->mlx, mlx->window);
	parse(env);
	print_vertical_lines(mlx, env);
	print_horizontal_lines(mlx, env);
}

void	launch_fdf(t_mlx *mlx, t_env *env)
{
	t_data		data;

	data.mlx = mlx;
	data.env = env;
	mlx_key_hook(mlx->window, key_hooks, &data);
	mlx_loop(mlx->mlx);
}
