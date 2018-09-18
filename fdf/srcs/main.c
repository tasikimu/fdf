/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 10:49:48 by tasikimu          #+#    #+#             */
/*   Updated: 2018/07/26 12:54:23 by tasikimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		display_control(void)
{
	ft_putendl_fd("# # # # # # # # # # # # # # # #", 1);
	ft_putendl_fd("#  tasikimu....controls :     #", 1);
	ft_putendl_fd("#-----------------------------#", 1);
	ft_putendl_fd("#  R : reset default config.  #", 1);
	ft_putendl_fd("#  Q  : increase width map.   #", 1);
	ft_putendl_fd("#  E  : decrease width map.   #", 1);
	ft_putendl_fd("#  ^  : move up map.          #", 1);
	ft_putendl_fd("#  v  : move down map.        #", 1);
	ft_putendl_fd("#  <  : move left map.        #", 1);
	ft_putendl_fd("#  >  : move right map.       #", 1);
	ft_putendl_fd("#  115  : increase relief.    #", 1);
	ft_putendl_fd("#  119  : decrease relief.    #", 1);
	ft_putendl_fd("#  +  : increase size map.    #", 1);
	ft_putendl_fd("#  -  : decrease size map.    #", 1);
	ft_putendl_fd("# # # # # # # # # # # # # # # #", 1);
}

int				main(int ac, char **av)
{
	t_env *env;
	t_mlx *mlx;

	if (ac == 2)
	{
		init_env();
		env = recover_env();
		env->file_name = av[1];
		read_file(env);
		parse(env);
		if (env->error == 1)
			exit(0);
		mlx = init_mlx();
		display_control();
		print_vertical_lines(mlx, env);
		print_horizontal_lines(mlx, env);
		launch_fdf(mlx, env);
		return (0);
	}
	else
		ft_putendl_fd("Invalid number of argument", 2);
}
