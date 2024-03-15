/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:36:00 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/03/14 20:54:58 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	print_pipex(t_pipex *data)
{
	int	cmd_nb;
	int	args_nb;
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (!data)
	{
		ft_printf("NO DATA");
		return ;
	}
	if (!data->cmds)
	{
		ft_printf("NO CMDS\n");
		return ;
	}
	cmd_nb = ft_arrlen((void **)data->cmds);
	ft_printf("data : %d commandes\n", cmd_nb);
	while (++i < cmd_nb)
	{
		if (data->cmds[i])
		{
			args_nb = data->cmds[i]->argc;
			ft_printf("\t CMD[%d] : %d ARGS\n", i, args_nb);
			while (++j < args_nb)
			{
				if (data->cmds[i]->argv[j])
					ft_printf("\t\t-%s\n", data->cmds[i]->argv[j]);
				else
					ft_printf("\t\tNO DATA\n");
			}
			ft_printf("--------------------\n");
			j = -1;
		}
	}
	ft_printf("EOS\n\n");
}

int	main(void)
{
	t_pipex *test = (t_pipex *)malloc(sizeof(t_pipex));
	test->f1_path = ft_strdup("ABC");
	test->f2_path = ft_strdup("DEF");
	get_path(test);
	test->fd_in = 0;
	test->fd_out = 1;

	t_cmd *c1 = (t_cmd *)malloc(sizeof(t_cmd));
	c1->argv = (char **)malloc(sizeof(char *) * 3);
	c1->argv[0] = ft_strdup("c1 s1");
	c1->argv[1] = ft_strdup("c1 s2");
	c1->argv[2] = NULL;
	c1->argc = 2;
	t_cmd *c2 = (t_cmd *)malloc(sizeof(t_cmd));
	c2->argv = (char **)malloc(sizeof(char *) * 3);
	c2->argv[0] = ft_strdup("c2 s1");
	c2->argv[1] = ft_strdup("c2 s2");
	c2->argv[2] = NULL;
	c2->argc = 2;

	test->cmds = (t_cmd **)malloc(sizeof(t_cmd *) * 3);
	test->cmds[0] = c1;
	test->cmds[1] = c2;
	test->cmds[2] = NULL;

	print_pipex(test);
	clear_data(test);
	print_pipex(test);
	free(test);
	return (0);
}