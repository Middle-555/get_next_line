/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:04:50 by kpourcel          #+#    #+#             */
/*   Updated: 2023/11/27 17:18:11 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Permet de trouver un caractère choisit dans un tableau 
/ une chaine de caractère.*/
char	*ft_strchr(const char *s1, int c)
{
	while (*s1 != (char)c)
	{
		if (*s1 == '\0')
			return (NULL);
		s1++;
	}
	return ((char *)s1);
}

/* Permet de malloc + cat deux chaines vers une 3 ème. */
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2 || !s1)
		return (NULL);
	s3 = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	k = -1;
	while (s2[++k])
		s3[i + k] = s2[k];
	s3[i + k] = '\0';
	free (s1);
	return (s3);
}

/* Donne la taille d'une chaine de caractère */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

/* Permet de rajouter le \0 que l'on recherchera plus tard */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *)(s);
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
}

/* Malloc + bzero*/

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*s1;

	s1 = malloc(nbr * size);
	if (!s1)
		return (NULL);
	ft_bzero(s1, nbr * size);
	return (s1);
}
