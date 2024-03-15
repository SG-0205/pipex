/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:05:00 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/03/15 11:49:00 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	del_cmd(t_pipex *data)
{
	int	i;
	int	j;

	if (!data->cmds)
	{
		ft_printf("del_cmd : %s\n", strerror(EFAULT));
		return ;
	}
	i = ft_arrlen((void **)data->cmds);
	while (--i >= 0)
	{
		j = ft_arrlen((void **)data->cmds[i]->argv);
		while (--j >= 0)
			(free(data->cmds[i]->argv[j]), data->cmds[i]->argc -= 1);
		free(data->cmds[i]->argv);
	}
	i = ft_arrlen((void **)data->cmds);
	while (--i >= 0)
		(free(data->cmds[i]), data->cmds[i] = NULL);
	(free(data->cmds), data->cmds = NULL);
}

void	clear_data(t_pipex *data)
{
	if (!data)
		(ft_printf("clear_data : %s\n", strerror(EFAULT)), exit(EFAULT));
	if (data->f1_path)
		free(data->f1_path);
	if (data->f2_path)
		free(data->f2_path);
	if (data->path_env)
		(free(data->path_env[0]), free(data->path_env));
	if (data->cmds)
		del_cmd(data);
}

int	**create_fd(t_pipex *data)
{
	//MAKE FD WHILE
}

void	get_path(t_pipex *data)
{
	int		i;
	char	**env;

	i = -1;
	env = __environ;
	while (ft_strncmp(env[++i], "PATH=", 5) != 0)
		;
	data->path_env = (char **)malloc(sizeof(char *) * 2);
	if (!data->path_env)
		(ft_printf("get_path : %s\n", strerror(ENOMEM)),
			data->path_env[1] = NULL);
	data->path_env[0] = ft_strdup(env[i]);
	if (!data->path_env[0])
		ft_printf("get_path : %s\n", strerror(ENOMEM));
}

void	init_data(t_pipex *data, char **argv)
{
	(void)data;
	(void)argv;
}
