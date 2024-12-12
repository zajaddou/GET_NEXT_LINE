
#include "get_next_line.h"

char *read_all_file(int fd)
{
	char 	*old;
    char	*buffer;
    char	*result;
    int		count;

    result = NULL;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return NULL;
    while (1)
    {
        count = read(fd, buffer, BUFFER_SIZE);
        if (count <= 0)  // ENF or Err
            break;
        buffer[count] = '\0';
		old = result;
        result = ft_strjoin(result, buffer);
		free(old);
        if (!result)
            break;
    }

    free(buffer);
    return result;
}

char    *ft_get_line(char **src)
{
    char    *result;
    char    *newline;
    int     index;

    if (!*src || !**src )
        return NULL;

    newline = ft_strchr(*src, '\n');
    if (newline)
        index = newline - *src;
    else
        index = ft_strlen(*src);

    result = (char *)malloc(sizeof(char) * (index + 2));
    if (!result)
        return NULL;

    ft_strncpy(result, *src, index + 1);
    result[index + 1] = '\0';

    *src += index + 1;
    return result;
}

char    *get_next_line(int fd)
{
    static char *storage;
    char        *result;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
        return NULL;

    if (!storage) {
        storage = read_all_file(fd);
        if (!storage)
            return NULL;
    }

    result = ft_get_line(&storage);

    if (!result || !*storage)
        storage = NULL;

    if (storage == result)
    {
        free(result);
        free(storage);
        storage = NULL;
    }

    return result;
}
