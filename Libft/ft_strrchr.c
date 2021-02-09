/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonzal <angonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:39:11 by angonzal          #+#    #+#             */
/*   Updated: 2021/02/01 15:54:52 by angonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			size;

	size = ft_strlen((char *)s);
	while (s[size] != c && size > 0)
		size--;
	if (s[size] == c)
		return ((char *)(s + size));
	return (0);
}
