/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 10:50:15 by tasikimu          #+#    #+#             */
/*   Updated: 2018/07/26 12:53:13 by tasikimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_env		*recover_env(void)
{
	static t_env	env;

	return (&env);
}

void		init_env(void)
{
	t_env		*env;

	env = (t_env*)malloc(sizeof(t_env));
	env = recover_env();
	env->tab_width = NULL;
	env->coord = NULL;
	env->height_tile = NULL;
	env->list = NULL;
	env->error = 0;
	env->height = 0;
	env->width = 0;
	env->depth = 4;
	env->view.x = 20;
	env->view.y = 10;
	env->rot.x = 0;
	env->rot.y = 0;
	env->fd = 0;
}

void		init_delta(t_delta *delta, t_point start, t_point end)
{
	delta->x = end.x - start.x;
	delta->y = end.y - start.y;
	delta->abs_x = ft_positive(delta->x);
	delta->abs_y = ft_positive(delta->y);
}

t_mlx		*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y, "FDF");
	return (mlx);
}
