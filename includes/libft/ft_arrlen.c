/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:07:05 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/03/14 19:27:49 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arrlen(void **array)
{
	int	size;

	size = -1;
	if (!array)
		return (size);
	while (array[++size])
		;
	return (size);
}

// int	main(void)
// {
// 	t_bool *array[] = {TRUE, TRUE, FALSE, NULL};

// 	ft_printf("3 = %d\n", ft_arrlen((void **)array));
// 	return (0);
// }