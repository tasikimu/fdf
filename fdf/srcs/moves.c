/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 10:49:32 by tasikimu          #+#    #+#             */
/*   Updated: 2018/07/26 12:54:33 by tasikimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	depth(t_mlx *mlx, t_env *env, int keycode)
{
	env->depth += keycode == 115 ? 1 : -1;
	reload_fdf(mlx, env);
}

void	zoom(t_mlx *mlx, t_env *env, int keycode)
{
	env->view.x += keycode == 69 ? 2 : -2;
	env->view.y = env->view.x / 2;
	reload_fdf(mlx, env);
}

void	normal_mod(t_mlx *mlx, t_env *env, int keycode)
{
	if (keycode == 15)
	{
		env->rot.y = 0;
		env->rot.x = 0;
		env->view.x = 20;
		env->view.y = 10;
		env->depth = 4;
	}
	reload_fdf(mlx, env);
}

void	rot(t_mlx *mlx, t_env *env, int keycode)
{
	env->view.x += keycode == 12 ? 10 : -10;
	reload_fdf(mlx, env);
}

void	l_r_up_down(t_mlx *mlx, t_env *env, int keycode)
{
	if (keycode == 124 || keycode == 123)
		env->rot.x += keycode == 124 ? 10 : -10;
	else if (keycode == 125 || keycode == 126)
	{
		env->rot.x += keycode == 125 ? 10 : -10;
		env->rot.y += keycode == 125 ? 10 : -10;
	}
	reload_fdf(mlx, env);
}
