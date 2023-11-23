/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:35:08 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/11/16 22:14:15 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *manage_reste(char *reste, int n)
{
	int	i;
	char *renvoi;

	i = 0;
	if (n < BUFFER_SIZE)              // si n est inf a Buffer size alors read a fini de lire
		return(0);                          // on revoi rien du coup
	while (reste[i] != 0)
	{
		if (reste[i] == '\n')                       // si tu trouve un \n dans reste
			renvoi = strchr(reste, '\n');        // tu mets dans renvoi de : \n a la fin 
		i++; 
	}	
	return (renvoi);
}

char	*get_next_line(int fd)
{
	char	*s;   //  string reponse 
	char	*buf; 
	char	*retour_reste;	
	ssize_t	n; //   nombre de caracter lu par read 
	int		i; 
	char	*reste; 

	i = 0; 
	n = BUFFER_SIZE;
	buf = 

	while (n == BUFFER_SIZE && manage_reste(buf, n) == (BUFFER_SIZE + 1))
	{

	buf = malloc(sizeof(char *) * ((BUFFER_SIZE + 1) +  ?  )); // malloc buffer + 1
	if (!buf)
		return(0);

	n = read(fd, buf, BUFFER_SIZE);  // lis et recup Buffer Size caractere  
	buf[n] = '\0'; // rejoute le caractere nul a la fin de buf  
	
	if (n == 0)      // si loc = 0 soit read est terminee, soit buffsize = 0 
		return(0);   
	
	retour_reste = manage_reste(buf, n); // recupere le reste qui a ete travaille
	
// 	while (  )



	s = malloc(sizeof(char *) * (BUFFER_SIZE ) );


	if (retour_reste != 0)
	{ 
		while (retour_reste[i] != 0)
		{ 
					
		}		
	}
	}

	return (s);
}

int	main()
{
	int	fd; 

	fd = open("txt.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}


