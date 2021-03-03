/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angel <angel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:49:41 by angonzal          #+#    #+#             */
/*   Updated: 2021/03/03 22:04:39 by angel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t aux;

	if (!dst && !src)
		return (0);
	aux = 0;
	while (aux < n)
	{
		((unsigned char *)dst)[aux] = ((unsigned char *)src)[aux];
		aux++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char *s2;
	int aux;

	aux = ft_strlen(s1);
	if (!(s2 = (char *)malloc(aux + 1)))
		return (0);
	ft_memcpy(s2, s1, aux + 1);
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t l;

	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	j;
	size_t aux;
	
	if (!s || !(new_str = (char *)malloc(len + 1)))
		return (0);
	j = 0;
	aux = ft_strlen(s);
	while (start < aux && j < len)
		new_str[j++] = s[start++];
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*first;
	int a;
	int b;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!s1 || !s2 ||
		!(new_str = (char *) malloc(sizeof(char) * (a + b + 1))))
		return (0);
	ft_memset(new_str, 0, (a+b+1));
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
	size_t aux;

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
	size_t	tot_size;
	void	*dst;

	tot_size = size * count;
	if (!(dst = malloc(size * count)))
		return (0);
	ft_memset(dst, 0, tot_size);
	return (dst);
}

char	*ft_strchr(char *s, int c)
{
	while (*s && c != *s)
		s++;
	if (c == *s)
		return ((char *)s);
	return (0);
}

char	*ft_struntilchr(char *s, int c)
{
	char *aux;

	aux = s;
	while (*s && c != *s)
		s++;
	if (c == *s)
		*(s) = '\0';
	return (aux);
}
