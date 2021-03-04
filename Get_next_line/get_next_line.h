/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angel <angel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:49:38 by angonzal          #+#    #+#             */
/*   Updated: 2021/03/04 10:16:31 by angonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>

# define IS_ERROR -1
# define END_OF_FILE 0
# define IS_END_LINE 1
# define NO_END_LINE 0

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

#endif
