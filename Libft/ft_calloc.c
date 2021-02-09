/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonzal <angonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:46:27 by angonzal          #+#    #+#             */
/*   Updated: 2021/01/27 15:43:32 by angonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** calloc() allocates the memory and also initializes the allocated memory
** block to zero. If we try to access the content of these blocks then we’ll
** get 0.
*/

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
