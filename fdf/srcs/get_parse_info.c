/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parse_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 10:50:32 by tasikimu          #+#    #+#             */
/*   Updated: 2018/07/26 12:56:25 by tasikimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	error(void)
{
	recover_env()->error = 1;
	perror(NULL);
	exit(0);
}

void	parse(t_env *env)
{
	int			x;
	int			y;

	env->coord = (t_point**)malloc(sizeof(t_point*) * env->height);
	y = -1;
	while (++y < env->height)
	{
		env->coord[y] = (t_point*)malloc(sizeof(t_point) * env->tab_width[y]);
		x = -1;
		while (++x < env->width)
		{
			env->coord[y][x].x = (x - y) * env->view.x + PADDING_X + env->rot.x;
			env->coord[y][x].y = (x + y) * env->view.y + PADDING_Y
						- (env->height_tile[y][x] * env->depth) + env->rot.x;
		}
	}
}

void	get_width_height_map(t_env *env)
{
	char	*line;

	line = NULL;
	while (ft_get_next_line(env->fd, &line) > 0)
	{
		ft_lstaddend(&env->list, ft_lstnew(line, sizeof(char) *
												(ft_strlen(line) + 1)));
		env->height++;
	}
	close(env->fd);
	env->width = ft_count_raw_aoc(ft_strsplit(line, ' '));
}

void	read_file(t_env *env)
{
	char	**line;
	int		i;
	int		j;

	if (((env->fd = open(env->file_name, O_RDONLY)) == -1))
		error();
	get_width_height_map(env);
	env->height_tile = (int **)malloc(sizeof(int*) * env->height);
	env->tab_width = (int*)malloc(sizeof(int) * env->height);
	i = -1;
	while (++i < env->height)
	{
		line = ft_strsplit((char*)env->list->content, ' ');
		env->tab_width[i] = ft_count_raw_aoc(line);
		env->height_tile[i] = (int*)malloc(sizeof(int) *
				(env->tab_width[i] + 1));
		j = -1;
		while (++j < env->tab_width[i])
			env->height_tile[i][j] = ft_atoi(line[j]);
		env->list = env->list->next;
	}
	close(env->fd);
}
