/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonzal <angonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:04:55 by angonzal          #+#    #+#             */
/*   Updated: 2021/01/27 15:30:23 by angonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	size_t  es el tipo para enteros sin signo
*/

#include "libft.h"

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
