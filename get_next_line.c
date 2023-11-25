/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:04:16 by kpourcel          #+#    #+#             */
/*   Updated: 2023/11/25 18:57:07 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 1. Fonction qui récupère ce qui est lu et l'envoie dans notre variable statique 
char	*read_and_stock(int fd, char *buff)
{
	char	*stash;
	int		already_read;

	if (!buff) /* Si le buff est vide on le créer et lui alloue 1 octet pour pouvoir join par la suite. */ 
		buff = ft_calloc(1,1);
	already_read = 1; /* On initialise à 1 pour avoir au minimum 1 itération. */ 
	stash = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while(already_read > 0)
	{
		already_read = read(fd, stash, BUFFER_SIZE);
		if (already_read == -1) /* En cas d'érreur de lecture on return -1 et free.  */
		{
			free(stash);
			return (NULL);
		}
		stash[already_read] = 0; /* Si la lecture echoue ou alors lorsque l'on atteint la fin du fichier on met la valeur à 0. */ 
		stash = ft_strjoin(buff, stash); 
		if (ft_strchr(stash, '\n'))
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
	while(stash[i] && stash[i] != '\n')
	{
		i++;
	}
	new_line = i + 2; /* +2 car ajout du \n et \0*/
	line = ft_calloc(new_line, sizeof(char));
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
		line[i] = '\n';
	return (line);
}
// 3. Fonction qui clear tout ce qu'il y a avant le "\n" et garde que le reste. 
char	*ft_clear_and_save(char *stash)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	save = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (stash[i])
	{
		save[j] = stash[i];
		i++;
		j++;
	}
	free (stash);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (buffer);
		return (NULL);
	}
	buffer = read_and_stock(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_seg_line(buffer);
	buffer = ft_clear_and_save(buffer);
	return (line);	
}
 