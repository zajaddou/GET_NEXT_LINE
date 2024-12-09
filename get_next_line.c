/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 06:24:17 by zajaddou          #+#    #+#             */
/*   Updated: 2024/12/08 22:28:12 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*get_line(char **src)
{
	char	*result;
	int		i;
	int		index;

	index = 0;
	result = ft_strchr(*src, '\n');
	if(!result)
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

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);

	buffer[BUFFER_SIZE] = '\0';
	counter = 1;
	while (!ft_strchr(storage, '\n') && counter > 0)
	{
		counter = read(fd, buffer, BUFFER_SIZE);
		if(counter == 0)
		{
			break ;
		}
		storage = ft_strjoin(storage, buffer);
		
		if (!storage)
			break ;
	}
	result = get_line(&storage);
	
	return (result);
}
