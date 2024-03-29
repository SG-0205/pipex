/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:47:17 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/03/20 16:52:42 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	*data;

	data = (t_pipex *)malloc(sizeof(t_pipex));
	if (init_data(data, argv) == FALSE)
		(clear_data(data), free(data), exit(1));
	if (argc != 5)
		(ft_printf(RED BOLD "Mauvais nombre d'arguments\n" RESET),
				exit(EINVAL));
	while (1)
		;
	return (0);
}
