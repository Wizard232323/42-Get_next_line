/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <ekoubbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:41:15 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/22 18:29:19 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, char c)
{
    int i;
    
    i = 0; 
    while (s[i])
    {
        if (s[i] == c)
            return (s + i);
        i++; 
    }
        if (c == '\0')
            return (s + i);
    return(0);
}
int     ft_strlen(char *s)
{
    int i; 

    i = 0; 
    if (!s)
        return(0);
    while (s[i])
        i++; 
    return(i);
}

char    *ft_realloc(char *dest, char *src)
{
    int i;
    char *rep; 

    i = 0; 
    rep = malloc(sizeof(char) * ((ft_strlen(dest) + ft_strlen(src) + 1)));
    if(!rep)
       return(0);
    while (dest && dest[i])
    {
        rep[i] = dest[i];
        i++;
    }
    rep[i] = '\0';
	if (dest != NULL)
		free(dest);
    return(rep);
}

char *ft_strcat(char *dest, char *src)
{
    int i;
    int j;
  
    j = 0;
    dest = ft_realloc(dest, src);
    i = ft_strlen(dest);
    while (src && src[j])
    {
        dest[i + j] = src[j];
        j++; 
    }
    dest[i + j] = '\0';
    return(dest);
}
