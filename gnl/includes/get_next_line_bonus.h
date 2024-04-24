/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:52:56 by rgiraud           #+#    #+#             */
/*   Updated: 2024/04/23 13:53:45 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../../libft_mandatory/includes/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

char	*get_next_line(int fd);
char	*read_line(char buffer[BUFFER_SIZE + 1], int fd);
char	*ft_joinbuffer(char *str, char buffer[BUFFER_SIZE + 1]);

#endif