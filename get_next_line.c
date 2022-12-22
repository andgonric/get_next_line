/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andgonca <andgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:20:30 by andgonca          #+#    #+#             */
/*   Updated: 2022/12/04 21:20:30 by andgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = fd_to_str(fd, str); //funcao 2
	if (!str)
		return (NULL);
	return (ft_get_line(str)); // funcao 3
	//str = funcao_4(str);
	//size_t read(int fd, void *buf, size_t BUFFER_SIZE)
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("textos/texto1.txt", O_RDONLY);
	fd2 = open("textos/texto2.txt", O_RDONLY);
	fd3 = open("textos/texto3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/