/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:17:15 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/03/19 18:03:19 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	del_cmd(t_pipex *data)
{
	int	i;
	int	j;

	if (!data->cmds)
	{
		ft_printf("del_cmd : %s\n", strerror(errno));
		return ;
	}
	i = ft_arrlen((void **)data->cmds);
	while (--i > -1)
	{
		free(data->cmds[i]->path);
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

t_bool	find_cmd_path(t_pipex *data)
{
	char	**splitted_path;
	char	*path;
	int		i;

	if (!data->path_env)
		return (FALSE);
	splitted_path = ft_split(ft_strchr(data->path_env, '/'), ':');
	i = -1;
	while (data->cmds[++i])
	{
		path = check_access(splitted_path, data->cmds[i]->argv[0], X_OK);
		if (!path)
		{
			ft_printf("find_cmd_path : %s\n", strerror(errno));
			(clear_data(data), free(data), del_tmp_split(splitted_path));
			(free(splitted_path), exit(errno));
		}
		else
		{
			data->cmds[i]->path = ft_strdup(path);
			free(path);
		}
	}
	return (TRUE);
}

t_bool	create_cmd(t_pipex *data, char **argv)
{
	int		i;
	char	**cmd_split;

	i = -1;
	data->cmds = (t_cmd **)malloc(sizeof(t_cmd *) * 3);
	if (!data->cmds)
		return (FALSE);
	data->cmds[2] = NULL;
	while (++i < 2)
	{
		cmd_split = ft_split(argv[i + 2], ' ');
		data->cmds[i] = (t_cmd *)malloc(sizeof(t_cmd));
		if (!data->cmds[i])
			return (FALSE);
		data->cmds[i]->argc = ft_arrlen((void **)cmd_split);
		data->cmds[i]->argv = (char **)malloc(sizeof(char *)
				* (data->cmds[i]->argc + 1));
		if (!data->cmds[i]->argv)
			return (FALSE);
		data->cmds[i]->argv[data->cmds[i]->argc] = NULL;
		ft_arrdup((void **)data->cmds[i]->argv, (void **)cmd_split);
		(del_tmp_split(cmd_split), free(cmd_split));
	}
	return (find_cmd_path(data));
}

