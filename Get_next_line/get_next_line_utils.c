/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonzal <angonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:49:41 by angonzal          #+#    #+#             */
/*   Updated: 2021/02/10 19:54:40 by angonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	lenght;

	lenght = 0;
	while (str[lenght] != '\0')
		lenght++;
	return (lenght);
}

char	*ft_strdup(char *str1)
{
	char	*str2;
	size_t	lenght;
	size_t	aux;

	aux = 0;
	lenght = ft_strlen(str1);
	if (!(str2 = (char *)malloc(sizeof(char) * lenght + 1)))
		return (0);
	while (str1[aux] != '\0')
	{
		str2[aux] = str1[aux];
		aux++;
	}
	str2[aux] = '\0';
	return (str2);
}


