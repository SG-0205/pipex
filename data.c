/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:05:00 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/03/19 11:17:51 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

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

t_bool	create_fd(t_pipex *data)
{
	int	i;

	i = -1;
	data->fds = (int **)malloc(sizeof(int *) * 7);
	if (!data->fds)
		return (FALSE);
	data->fds[7] = NULL;
	while (data->fds[++i])
	{
		data->fds[i] = (int *)malloc(sizeof(int));
		if (!data->fds[i])
			return (FALSE);
	}
	return (TRUE);
}

t_bool	get_path(t_pipex *data)
{
	int		i;
	char	**env;

	i = -1;
	env = __environ;
	while (ft_strncmp(env[++i], "PATH=", 5) != 0)
		;
	data->path_env = (char **)malloc(sizeof(char *) * 2);
	data->path_env[1] = NULL;
	if (!data->path_env)
		return (FALSE);
	data->path_env[0] = ft_strdup(env[i]);
	if (!data->path_env[0])
		return (FALSE);
	return (TRUE);
}

t_bool	init_data(t_pipex *data, char **argv)
{
	data->f1_path = ft_strdup(argv[1]);
	if (!data->f1_path)
		return (FALSE);
	data->f2_path = ft_strdup(argv[4]);
	if (data->f2_path)
		return (FALSE);
	if (get_path(data) == FALSE)
	{
		ft_printf("get_path : %s\n", strerror(ENOMEM));
		return (FALSE);
	}
	if (create_fd(data) == FALSE)
	{
		ft_printf("create_fd : %s\n", strerror(ENOMEM));
		return (FALSE);
	}
	//CREATE CMDS
}
