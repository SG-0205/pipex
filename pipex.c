/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:47:17 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/03/14 20:05:16 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	*data;

	get_path("d");
	data = (t_pipex *)malloc(sizeof(t_pipex));
	init_data(data, argv);
	if (argc != 5)
		(ft_printf(RED BOLD "Mauvais nombre d'arguments\n" RESET),
				exit(EINVAL));
	(void)argv;
	while (1)
		;
	return (0);
}
