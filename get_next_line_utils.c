/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:04:50 by kpourcel          #+#    #+#             */
/*   Updated: 2023/11/25 18:56:23 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Permet de trouver un caractère choisit dans un tableau / une chaine de caractère.*/
char    *ft_strchr(const char *s, int c)
{
    while (*s != (char)c)
    {
        if (*s == '\0')
            return (NULL);
        s++;
    }
    return ((char *)s);
}

/* Permet de malloc + cat deux chaines vers une 3 ème. */
char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	char	*s3;

	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		s3[i] = s2[k];
		k++;
		i++;
	}
	s3[i] = '\0';
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
