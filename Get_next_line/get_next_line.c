/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angel <angel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:49:34 by angonzal          #+#    #+#             */
/*   Updated: 2021/03/04 09:55:34 by angonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_pointer(char **pointer)
{
	if (!(!pointer))
	{
		free(*pointer);
		*pointer = NULL;
	}
}

int		ft_is_there_end_line(char **static_text2, char **line)
{
	size_t		n;
	char		*aux_text2;
	size_t		len;

	n = 0;
	aux_text2 = NULL;
	len = 0;
	while (*static_text2[len] != 0)
		len++;
	while (n < len)
	{
		if (static_text2[0][n] == '\n')
		{
			*line = ft_substr(*static_text2, 0, n);
			aux_text2 = ft_substr(*static_text2, n + 1, (len - n));
			ft_free_pointer(static_text2);
			*static_text2 = aux_text2;
			return (IS_END_LINE);
		}
		n++;
	}
	return (NO_END_LINE);
}

int		ft_end_file(char **static_text3, char **line)
{
	if (!*static_text3)
	{
		*line = ft_strdup("");
		return (END_OF_FILE);
	}
	if (ft_is_there_end_line(static_text3, line))
		return (IS_END_LINE);
	*line = ft_strdup(*static_text3);
	ft_free_pointer(static_text3);
	return (END_OF_FILE);
}

int		get_next_line(int fd, char **line)
{
	ssize_t		nr_bytes_read;
	static char	*static_text;
	char		*aux_text;
	char		*str_readfromfile;

	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
	(!(str_readfromfile = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char)))))
		return (IS_ERROR);
	while ((nr_bytes_read = read(fd, str_readfromfile, BUFFER_SIZE)) > 0)
	{
		str_readfromfile[nr_bytes_read] = '\0';
		if (static_text)
		{
			aux_text = ft_strjoin(static_text, str_readfromfile);
			ft_free_pointer(&static_text);
			static_text = aux_text;
		}
		!static_text ? (static_text = ft_strdup(str_readfromfile)) : 0;
		if (ft_is_there_end_line(&static_text, line))
		{
			ft_free_pointer(&str_readfromfile);
			return (IS_END_LINE);
		}
	}
	ft_free_pointer(&str_readfromfile);
	if (nr_bytes_read == -1)
		return (IS_ERROR);
	if (ft_end_file(&static_text, line))
		return (IS_END_LINE);
	return (END_OF_FILE);
}
