/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:04:16 by kpourcel          #+#    #+#             */
/*   Updated: 2023/11/23 19:11:23 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), buffer == NULL);
	buffer = read_and_stock(fd, buffer);
	
		
}

// 1. Fonction qui récupère ce qui est lu et l'envoie dans notre variable statique 
char	read_and_stock(int fd, char *buff)
{
	char	*stash;
	int		already_read;

	if (!buff) /* Si le buff est vide on le créer et lui alloue 1 octet pour pouvoir join par la suite. */ 
		buff = ft_calloc(sizeof(char) * 1);
	stash = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	already_read = 1; /* On initialise à 1 pour avoir au minimum 1 itération. */ 
	while(already_read > 0)
	{
		already_read = read(fd, stash, BUFFER_SIZE);
		if (already_read == -1) /* En cas d'érreur de lecture on return -1 et free.  */
		{
			free(stash);
			return (NULL);
		}
		stash[already_read] == 0; /* Si la lecture echoue ou alors lorsque l'on atteint la fin du fichier on met la valeur à 0. */ 
		stash = ft_strjoin(buff, stash); 
		if (ft_strchr(stash, "\n"))
			break;
	}
	free(stash);
	return (buff);
}
/* 2. This function read until it find a '\n' and save it in stash. */
char	*ft_seg_line(char *stash)
{
	char	*line;
	int		i;
	int		new_line;

	i = 0;
	if (!stash)
		return (NULL);
	while(!stash[i] && stash[i] != '\n')
	{
		i++;
	}
	new_line = i + 2; /* +2 car ajout du \n et \0*/
	line = ft_calloc(new_line, sizeof(char));
	while (!stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}
// 3. Fonction qui clear tout ce qu'il y a avant le "\n" et garde que le reste. 
// 4.
// read écrase le buffer à chaque fois qu'elle repasse il faut donc stocker ce que l'on met dans le buffer dans une variable statique 