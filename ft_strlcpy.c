/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:40:37 by rgiraud           #+#    #+#             */
/*   Updated: 2023/10/04 11:32:45 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (src[i] && i < (n - 1))
		{
			dst[i] = src[i];
			i++;
		}
		if (n != 0)
			dst[i] = '\0';
	}
	return (ft_strlen(src));
}
