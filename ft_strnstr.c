/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:00:27 by rgiraud           #+#    #+#             */
/*   Updated: 2023/10/03 11:42:10 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*chaine;

	chaine = (char *)haystack;
	if (!needle || *needle == '\0')
		return (chaine);
	i = 0;
	while (chaine[i] && i < len)
	{
		j = 0;
		if (chaine[i] == needle[j])
		{
			while (chaine[i] && needle[j] && chaine[i + j] == needle[j] && i
				+ j < len)
			{
				j++;
			}
			if (needle[j] == '\0')
				return (chaine + i);
		}
		i++;
	}
	return (NULL);
}
