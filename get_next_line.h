/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:41:15 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/22 16:25:52 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
char	*get_next_line(int fd);
char	*ft_strchr(char *s, char c);
int		ft_strlen(char *s);
char	*ft_realloc(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_good(char *line);
int		ft_slash(char *buf);

#endif

