/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:49:41 by angonzal          #+#    #+#             */
/*   Updated: 2021/03/04 20:04:26 by angonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		aux;
	size_t		temp;

	aux = 0;
	while (s1[aux] != 0)
		aux++;
	if (!(s2 = (char *)malloc(aux + 1)))
		return (0);
	aux = aux + 1;
	temp = 0;
	while (temp < aux)
	{
		((unsigned char *)s2)[temp] = ((unsigned char *)s1)[temp];
		temp++;
	}
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new_str;
	size_t		j;
	size_t		aux;

	if (!s || !(new_str = (char *)malloc(len + 1)))
		return (0);
	j = 0;
	aux = 0;
	while (s[aux] != 0)
		aux++;
	while (start < aux && j < len)
		new_str[j++] = s[start++];
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*first;
	int		a;
	int		b;

	a = 0;
	while (s1[a] != 0)
		a++;
	b = 0;
	while (s2[b] != 0)
		b++;
	if (!s1 || !s2 ||
		!(new_str = (char *)malloc(sizeof(char) * (a + b + 1))))
		return (0);
	ft_memset(new_str, 0, (a + b + 1));
	first = new_str;
	while (*s1)
		*new_str++ = *s1++;
	while (*s2)
		*new_str++ = *s2++;
	*new_str = '\0';
	return (first);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		aux;

	aux = 0;
	while (aux < len)
	{
		((unsigned char *)b)[aux] = (unsigned char)c;
		aux++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t		tot_size;
	void		*dst;

	tot_size = size * count;
	if (!(dst = malloc(size * count)))
		return (0);
	ft_memset(dst, 0, tot_size);
	return (dst);
}
