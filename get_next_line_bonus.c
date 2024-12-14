/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:24:21 by zajaddou          #+#    #+#             */
/*   Updated: 2024/12/14 15:05:12 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static char	*read_line(int fd, char *str)
{
	char	*buff;
	char	*temp;
	int		bread;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(str), str = NULL, NULL);
	while (!ft_strchr(str, '\n'))
	{
		bread = read(fd, buff, BUFFER_SIZE);
		if (bread < 0)
			return (free(buff), buff = NULL, free(str), str = NULL, NULL);
		if (bread == 0)
			break ;
		buff[bread] = '\0';
		temp = str;
		str = ft_strjoin(str, buff);
		free(temp);
		temp = NULL;
		if (!str)
			return (free(buff), buff = NULL, NULL);
	}
	free(buff);
	buff = NULL;
	return (str);
}

static char	*one_line(char **src)
{
	char	*result;
	char	*temp;
	int		index;
	char	*new;

	if (!*src || !**src)
		return (NULL);
	new = ft_strchr(*src, '\n');
	if (new)
		index = new - *src;
	else
		index = ft_strlen(*src) - 1;
	result = malloc(sizeof(char) * (index + 2));
	if (!result)
		return (NULL);
	ft_strncpy(result, *src, index + 1);
	result[index + 1] = '\0';
	if (new)
		temp = ft_strdup(*src + index + 1);
	else
		temp = NULL;
	free(*src);
	*src = NULL;
	*src = temp;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*fd_buffers[OPEN_MAX];
	char		*res;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0
		|| !(BUFFER_SIZE < INT_MAX))
		return (NULL);
	fd_buffers[fd] = read_line(fd, fd_buffers[fd]);
	if (!fd_buffers[fd])
		return (NULL);
	res = one_line(&fd_buffers[fd]);
	if (!fd_buffers[fd] || !*fd_buffers[fd])
	{
		free(fd_buffers[fd]);
		fd_buffers[fd] = NULL;
	}
	return (res);
}
