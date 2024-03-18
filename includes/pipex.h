/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:48:27 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/03/18 15:00:27 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

typedef	struct s_cmd
{
	int		argc;
	char	**argv;
}	t_cmd;

typedef struct s_pipex
{
	int		**fds;
	char	*f1_path;
	char	*f2_path;
	char	**path_env;
	t_cmd	**cmds;
} t_pipex;

void	clear_data(t_pipex *data);
void	del_cmd(t_pipex *data);
t_bool	get_path(t_pipex *data);
t_bool	init_data(t_pipex *data, char **argv);

#endif