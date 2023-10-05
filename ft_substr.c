/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:27:25 by rgiraud           #+#    #+#             */
/*   Updated: 2023/10/05 18:52:15 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len_result;
	char	*result;

	len_s = ft_strlen(s);
	if (start > len_s)
		return ("");
	if (len_s - start > len)
		len_result = len;
	else
		len_result = len_s - start;
	result = (char *)malloc((len_result + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
