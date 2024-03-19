/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:17:15 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/03/19 11:47:36 by sgoldenb         ###   ########.fr       */
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

t_bool	create_cmd(t_pipex *data, char **argv)
{
	int		i;
	char	**cmd_split;

	i = -1;
	data->cmds = (t_cmd **)malloc(sizeof(t_cmd *) * 3);
	if (!data->cmds)
		return (FALSE);
	data->cmds[2] = NULL;
	while (++i < 1)
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
		free(cmd_split);
	}
	return (TRUE);
}
