/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:16:24 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/21 22:09:42 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *good(char *temp)
{
	int		i;
	char	*newline; 

	i = 0;
	newline = malloc(sizeof(char) * (ft_strlen(temp)) + 1);
	if (!newline)
		return(0);
	while (temp[i] != 0 && temp[i] != '\n') 
	{
		newline[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		newline[i] = '\n';
		i++;
	}
	newline[i] = '\0';
//	printf("%s\n", newline);
//	printf("%s\n", temp);
	free(temp);
	return(newline);
}

int	slash(char *buf)
{
	int	i;

	i = 0; 

	while (buf[i] != 0)
	{
		if (buf[i] == '\n')
			return(1);
		i++; 
	}
	return(0);
}

char *get_next_line(int fd)
{
	char		*line; // ligne reponse
	char		*buf; // buffer de read 
	static char	*temp = NULL; // tampon static 
	ssize_t		n; // buffer size

//	temp = 0; 
	n = BUFFER_SIZE;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // malloc de buff
	if (!buf)
		return(0);
	buf[0] = '\0';
	line = ft_strjoin(temp, NULL);
	temp = NULL;
	while (n == BUFFER_SIZE && slash(buf) == 0)
	{
		n = read(fd, buf, BUFFER_SIZE); //recup buffer_size caractere et l met dans buff renvoi n
		if (n < 0)
		{
			free(buf);
			free(line);
			free(temp);
			temp = NULL;
			return (NULL);
		}
		buf[n] = '\0';
		line = ft_strjoin(line, buf); 	
		if (ft_strchr(line, '\n') != 0)
		{
			temp = ft_strjoin(NULL, ft_strchr(line, '\n') + 1);
			free(buf);
			//printf("temp = %s\n", temp);
			return (good(line));
		}
//		printf("temp2 = %s\n buf2 = %s\n ", temp, buf);
	}
	free(buf);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return(line);
}

int	main ()
{
	int	fd;
	char	*test; 
	int	i;

	i = 0;
	test = "";
	fd = open("txt.txt" , O_RDONLY);
	while (test)
	{
		test = get_next_line(fd);
		printf("%s" , test); 
		free(test);
		i++;
	}
	return (0);
}

