/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:51:20 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/23 13:54:45 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

/* Returns the result of strjoin of str + buffer & frees str */
char	*ft_joinbuffer(char *str, char buffer[BUFFER_SIZE + 1])
{
	char	*line;

	if (buffer == NULL)
		return (NULL);
	else if (str == NULL)
		return (ft_strdup(buffer));
	line = ft_strjoin(str, buffer);
	free(str);
	return (line);
}

/* 	Read from a file BUFFER_SIZE bytes at a time.
	If EOF or \n is found, return string of all read content.
	If no bytes were read and there's nothing in BUFFER, return NULL */
char	*read_line(char buffer[BUFFER_SIZE + 1], int fd)
{
	char	*line;
	int		bytes_read;

	if (ft_strchr(buffer, '\n'))
		return (ft_strdup(buffer));
	line = ft_strdup(buffer);
	if (line == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (!bytes_read && !buffer[0])
		return (free(line), NULL);
	while (bytes_read > 0)
	{
		line = ft_joinbuffer(line, buffer);
		if (line == NULL)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			return (line);
		ft_bzero(buffer, BUFFER_SIZE);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

/*	Return a copied allocated string of READ_RESULT up to and including \n
	If no \n is found, simply returns a duplicated READ_RESULT */
char	*get_line(char *read_result)
{
	char	*line;
	int		line_size;

	if (read_result == NULL)
		return (NULL);
	line_size = 0;
	while (read_result[line_size] && read_result[line_size] != '\n')
		line_size++;
	if (read_result[line_size] == '\0')
		return (ft_strdup(read_result));
	line_size++;
	line = malloc(sizeof(char) * (line_size + 1));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, read_result, line_size + 1);
	return (line);
}

/*	Remove last line content of BUFFER and get start of next line in place
	If there's nothing after new line, sets all of buffer to 0 */
void	reset_buffer(char buffer[BUFFER_SIZE + 1])
{
	int	len;
	int	i;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\0')
		return (ft_bzero(buffer, BUFFER_SIZE));
	len++;
	i = 0;
	while (buffer[len + i])
	{
		buffer[i] = buffer[len + i];
		i++;
	}
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

/* 	Returns the next line of file representated by FD.
	Line is allocated in memory and should be free'd by caller
	Returns NULL if EOF or on error. */
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*read_result;
	char		*line;

	read_result = NULL;
	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, read_result, 0) == -1)
		return (NULL);
	read_result = read_line(buffer, fd);
	if (read_result == NULL)
		return (NULL);
	line = get_line(read_result);
	free(read_result);
	if (line == NULL)
		return (NULL);
	reset_buffer(buffer);
	return (line);
}
