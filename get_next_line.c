/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:41:15 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/22 18:34:18 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_good(char *line)
{
    int     i; 
    char    *newline;

    i = 0; 
    newline = malloc(sizeof(char) * (ft_strlen(line) + 1));
    if (!newline)
        return(0);
    while (line && line[i] != '\n')
    {
        newline[i] = line[i]; 
        i++;
    }
    if (line[i] == '\n')
        newline[i] = '\n'; 
    i++; 
    newline[i] = '\0'; 
    free(line);
    return(newline); 
}


int     ft_slash(char *buf)
{
    int i;

    i = 0; 
    while (buf[i] != '\0')
    {
        if (buf[i] == '\n')
        {
            free(buf);
            return(1);
        }   
        i++;
    }
    return (0);
}


char    *get_next_line(int fd)
{
    static char     *temp = 0; // static 
    char            *buf;  // buf du read
    char            *line; // reponse GNL
    ssize_t         n; // controle du read 

    n = BUFFER_SIZE;
    line =  ft_strcat(temp, NULL); 
	temp = NULL;
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return(0);
    buf[0] = '\0'; //
    while (1) //ft_slash(buf) == 0) 
    {
	    n = read(fd, buf, BUFFER_SIZE);
	    if (n < 0)
	    {
			if (temp != NULL)
			{
				free(temp);
				temp = NULL;
			}
	        free(buf);
	        free(line);
	        return(NULL); 
	    }
	    buf[n] = '\0';
	    line = ft_strcat(line, buf);
        if (ft_strchr(line, '\n') != 0)
        {
            temp = ft_strcat(NULL, ft_strchr(line, '\n') + 1);
            free(buf);
            return(ft_good(line));
        }
		if (n == 0)
		{
			if (temp != NULL)
			{
				free(temp);
				temp = NULL;
			}
			free(buf);
			return (line);
		}
    }
    return (NULL);
}
  
/* int main()
{
	int     fd;
	char    *line; 
	int     i;

	i = 0;
	line = "";
	fd = open("41_with_nl", O_RDONLY);
	while (line != NULL && i < 3)
	{
		line = get_next_line(fd);
		printf("%d: %s", i, line);
		if (line != NULL)
			free(line);
		i++;
	}
	return (0);
} */
