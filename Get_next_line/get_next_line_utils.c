/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonzal <angonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:49:41 by angonzal          #+#    #+#             */
/*   Updated: 2021/02/11 20:29:33 by angonzal         ###   ########.fr       */
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
	size_t	aux;

	aux = 0;
	if (!(str2 = (char *)malloc(sizeof(char) * ft_strlen(str1) + 1)))
		return (0);
	while (str1[aux] != '\0')
	{
		str2[aux] = str1[aux];
		aux++;
	}
	str2[aux] = '\0';
	return (str2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	j;

	if (!s || !(new_str = (char *)malloc(len + 1)))
		return (0);
	j = 0;
	while (start < ft_strlen(s) && j < len)
		new_str[j++] = s[start++];
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*first;

	if (!s1 || !s2 ||
		!(new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	first = new_str;
	while (*s1)
		*new_str++ = *s1++;
	while (*s2)
		*new_str++ = *s2++;
	*new_str = '\0';
	return (first);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && c != *s)
		s++;
	if (c == *s)
		return ((char *)s);
	return (0);
}
