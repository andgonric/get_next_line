/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andgonca <andgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:27:37 by andgonca          #+#    #+#             */
/*   Updated: 2022/12/20 22:10:44 by andgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

int	ft_strchr(char *str)
{
	int		n;

	n = 0;
	if (!str)
		return (0);
	while (str[n] != '\0')
	{
		if (str[n] == '\n')
			return (n);
	n++;	
	}
	return (0);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		n;

	n = 0;
	while (str[n] || str[n] != '\n')
		n++;
	line = malloc(sizeof(char) * (n + 2));
	if (!line)
		return (NULL);
	n = 0;
	while (str[n] != '\n' || str[n])
	{
		line[n] = str[n];
		n++;
	}
	if (str[n] == '\n')
	{
		line[n] = '\n';
		n++;
	}
	line[n] = '\0';
	free(str);
	return (line);
}

char	*ft_strjoin(char *buff, char *str)
{
	size_t	n;
	size_t	n1;
	char	*str_ret;

	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	str_ret = malloc(sizeof(char) * ((ft_strlen(buff) + ft_strlen(str)) + 1));
	if (str_ret == NULL)
		return (NULL);
	n = -1;
	if (str)
		while (str[++n] != '\0')
			str_ret[n] = str[n];
	n1 = 0;
	while (buff[n1] != '\0')
		str_ret[n++] = buff[n1++];
	str_ret[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (str_ret);
}

char	*fd_to_str(int fd, char *str)
{
	char	*buff;
	int		size;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	size = 1;
	while (!ft_strchr(str) && size != 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[size] = '\0';
		str = ft_strjoin(buff, str);
	}
	free(buff);
	return (str);
}