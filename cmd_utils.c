/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:23:58 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/03/19 18:09:52 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	del_tmp_split(char **splitted)
{
	int	size;

	size = ft_arrlen((void **)splitted);
	while (--size > -1)
		free(splitted[size]);
}

char	*check_access(char **directories, char *to_find, int perm_code)
{
	int		nb_dir;
	char	*path;

	nb_dir = ft_arrlen((void **)directories);
	path = NULL;
	while (-- nb_dir > -1)
	{
		path = ft_strjoinsep(directories[nb_dir], to_find, '/');
		if (access(path, perm_code) == 0)
			break ;
		(free(path), path = NULL);
	}
	return (path);
}
