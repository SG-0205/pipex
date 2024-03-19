/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:48:27 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/03/19 17:35:04 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	int		argc;
	char	**argv;
	char	*path;
}			t_cmd;

typedef struct s_pipex
{
	int		**fds;
	char	*f1_path;
	char	*f2_path;
	char	*path_env;
	t_cmd	**cmds;
}			t_pipex;

void		clear_data(t_pipex *data);
void		del_cmd(t_pipex *data);
t_bool		get_path(t_pipex *data);
t_bool		init_data(t_pipex *data, char **argv);
t_bool		create_cmd(t_pipex *data, char **argv);
void		del_tmp_split(char **splitted);
char		*check_access(char **directories, char *to_find, int perm_code);

#endif