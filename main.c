/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddou <zajaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 06:26:20 by zajaddou          #+#    #+#             */
/*   Updated: 2024/12/10 04:11:30 by zajaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	src = get_next_line(fd);
	printf("%s", src );
	free(src);
	atexit(ft_);
}