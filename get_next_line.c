/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:25:41 by btomlins          #+#    #+#             */
/*   Updated: 2023/04/11 11:55:42 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*next(char **temp)
{
	char	*s;
	char	*ptr;

	ptr = *temp;
}

static char	*read_file(char *temp, int fd, char *buffer)
{
	ssize_t	i;

	i = 1;
	while (i && !ft_strchr (temp, '\n'))
	{
		r = read (fd, bufffer, BUFFER_SIZE);
		if (r == -1)
		{
			free (buffer);
			free (temp);
			return (0);
		}
		buffer[r] = 0;
		temp = ft_strjoin_free(temp, buffer);
		if (!temp)
		{
			free (buf);
			return (0);
		}
	}
	free (buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*temp[OPEN_MAX];
	char			*buffer;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (0);
	if (!temp[fd])
		temp[fd] = ft_strdup("");
	if (!temp[fd])
		return (0);
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free (temp[fd]);
		return (0);
	}
	temp[fd] = read_file(temp[fd], fd, buffer);
	if (!temp[fd])
		return (0);
	if (!*temp[fd])
	{
		free(temp[fd]);
		temp[fd] = 0;
		return (0);
	}
	return (next(&temp[fd]));
}
