#include "get_next_line.h"
void	ft_()
{
	system("leaks a.out");
}
int	main(void)
{
	int		fd;
	char	*src;

	fd = open("data.txt", O_RDONLY | O_CREAT, 0777);

	int max = 2;
	for(int i; i < max; i++)
	{
		src = get_next_line(fd);
		printf("%s",src);
		free(src);
	}

	atexit(ft_);
}
