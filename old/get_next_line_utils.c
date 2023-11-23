/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:53:32 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/18 03:53:23 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
		int i;

		 i = 0;
		 while (s[i])
		{
			if (s[i] == (char)c)
			return ((char *)s + i);
			i++;
		}
		if ((char)c == '\0')
			return ((char *)s + i);
		return (0);
}

/*
char    *ft_substr(char const *s, unsigned int start, size_t len)
 {
     size_t  i;
     size_t  j;
     char    *s2;

     i = 0;
     j = ft_strlen(s);
     if (start >= j)
         start = j;
     if (len >= j - start)
         len = j - start;
     s2 = (char *)malloc(len + 1);
     if (!s2)
         return (NULL);
     while (s[start] && i < len)
     {
         s2[i] = s[start];
         i++;
         start++;
     }
     s2[i] = '\0';
     return (s2);
 }
*/

size_t  ft_strlen(const char *s)
{
    size_t  i;
  
    i = 0;
	if (s == NULL)
		return(0);
    while (s[i] != 0)
		i++;
    return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
	size_t  i;
    size_t  j;
    size_t  k;
    size_t  l;
    char    *s3;
	
    i = ft_strlen(s1);
    j = ft_strlen(s2);
    k = 0;
    l = 0;
	
	s3 = (char *)malloc((i + j) + 1);
    if (!s3)
        return (NULL); 
    while (s1 != NULL && s1[k]) 
    {
        s3[k] = s1[k];
        k++;
    }
    while (s2 != NULL && s2[l])
    {
        s3[k + l] = s2[l];
        l++;
    }
	s3[k + l] = '\0';
	free(s1);
	return (s3);
}






