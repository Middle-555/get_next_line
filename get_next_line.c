/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:04:16 by kpourcel          #+#    #+#             */
/*   Updated: 2023/11/21 15:20:03 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
}


// 1. Fonction qui récupère ce qui est lu et l'envoie dans notre variable statique 
// 2. Fonction qui récupère jusqu'au "\n" et save. 
// 3. Fonction qui clear tout ce qu'il y a avant le "\n" et garde que le reste. 
// 4.