/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonzal <angonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:08:53 by angonzal          #+#    #+#             */
/*   Updated: 2021/02/03 17:43:56 by angonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	if (s[0] != c)
		words++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

int		ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	if (!s || !(new = malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			if (!(new[i] = (char *)malloc(sizeof(char) *
				ft_word_len(s, c) + 1)))
				return (NULL);
			while (*s != c && *s)
				new[i][j++] = *s++;
			new[i][j++] = '\0';
			i++;
		}
		else
			s++;
	}
	new[i] = NULL;
	return (new);
}
