/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:40:03 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/03/20 16:47:37 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_streplace(char **old, char *new)
{
	if (!old || !*old)
		return (NULL);
	new = ft_strdup(*old);
	ft_frptr((void **)old);
	return (new);
}