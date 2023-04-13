/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:25:41 by btomlins          #+#    #+#             */
/*   Updated: 2023/04/13 11:16:25 by btomlins         ###   ########.fr       */
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
	while (*ptr && *ptr != '\n')
		++ptr;
	ptr += (*ptr == '\n');
	s = ft_substr(*temp, 0, (size_t)(ptr - *temp));
	if (!s)
	{
		free (*temp);
		return (0);
	}
	ptr = ft_substr(ptr, 0, ft_strlen(ptr));
	free (*temp);
	*temp = ptr;
	return (s);
}

static char	*read_file(char *temp, int fd, char *buffer)
{
	ssize_t	i;

	i = 1;
	while (i && !ft_strchr (temp, '\n'))
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (buffer);
			free (temp);
			return (0);
		}
		buffer[i] = 0;
		temp = ft_strjoin_free(temp, buffer);
		if (!temp)
		{
			free (buffer);
			return (0);
		}
	}
	free (buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*temp[OPEN_LIMIT];
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
