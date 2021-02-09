/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonzal <angonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:12:28 by angonzal          #+#    #+#             */
/*   Updated: 2021/01/25 15:18:19 by angonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
