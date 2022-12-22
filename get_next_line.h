/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andgonca <andgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:18:32 by andgonca          #+#    #+#             */
/*   Updated: 2022/12/04 21:18:32 by andgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int	    ft_strchr(char *str);
char	*ft_get_line(char *str);
char	*ft_strjoin(char *buff, char *str);
char	*fd_to_str(int fd, char *str);
#endif
