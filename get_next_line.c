/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 06:24:17 by zajaddou          #+#    #+#             */
/*   Updated: 2024/12/07 06:25:29 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_index(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_line(int index, char **src)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (index + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (**src && i <= index)
	{
		result[i] = **src;
		(*src)++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*result;
	int		counter;
	int		index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 2));
	if (!buffer)
		return (NULL);
	counter = read(fd, buffer, BUFFER_SIZE);
	if (!counter)
	{
		free(buffer);
		return (NULL);
	}
	index = get_index(buffer);
	result = get_line(index, &buffer);
	return (result);
}
