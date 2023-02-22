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

char	*ft_new_str(char *str)
{
	char	*new;
	int		c;
	int		c1;

	c = 0;
	c1 = 0;
	while (str[c] != '\n' && str[c] != '\0')
		c++;
	if (str[c] == '\0' || (str[c] == '\n' && str[c + 1] == '\0'))
	{
		free(str);
		return (NULL);
	}
	new = malloc(sizeof(char) * ((ft_strlen(str) - c) + 1));
	if (!new)
		return (NULL);
	c++;
	c1 = 0;
	while (str[c] != '\0')
	{
		new[c1++] = str[c++];
	}
	new[c1] = '\0';
	free (str);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = fd_to_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_new_str(str);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	//int		fd2;
	//int		fd3;
	fd1 = open("textos/2", O_RDONLY);
	//fd2 = open("textos/texto2.txt", O_RDONLY);
	//fd3 = open("textos/texto3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		//line = get_next_line(fd2);
		//printf("line [%02d]: %s", i, line);
		//free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	//close(fd2);
	//close(fd3);
	return (0);
}*/