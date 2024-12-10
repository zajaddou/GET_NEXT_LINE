/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 06:24:17 by zajaddou          #+#    #+#             */
/*   Updated: 2024/12/10 06:10:19 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_empty_storage(char **storage)
{
	if (!*storage || **storage == '\0')
	{
		free(*storage);
		*storage = NULL;
		return (NULL);
	}
	return (*storage);
}

int	is_valid(int fd, char **storage)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		*storage = handle_empty_storage(storage);
		return (0);
	}
	return (1);
}

char	*get_next(char **src)
{
	char	*result;
	int		i;
	int		index;

	if (!*src || !**src)
		return (NULL);

	index = 0;
	result = ft_strchr(*src, '\n');
	if (!result)
		return (*src);
	index = result - *src;
	result = (char *)malloc(sizeof(char) * (index + 2));
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
	static char *storage;

	if (!is_valid(fd, &storage))
		return (NULL);

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);

	buffer[BUFFER_SIZE] = '\0';
	counter = 1;
	while (!ft_strchr(storage, '\n') && counter > 0)
	{
		counter = read(fd, buffer, BUFFER_SIZE);
		if (counter == 0)
			break;

		buffer[counter] = '\0';

		storage = ft_strjoin(storage, buffer);
		if (!storage)
			break;
	}

	free(buffer);
	if (counter == 0 && handle_empty_storage(&storage) == NULL)
		return (NULL);

	result = get_next(&storage);

	if (storage == result)
		storage = handle_empty_storage(&storage);

	return (result);
}
