/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:25:41 by btomlins          #+#    #+#             */
/*   Updated: 2023/04/19 14:44:07 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

/*Next: Extracts next line from a given string, stores to **temp.
  Finds position of the newline character or the end of the string.
  Creates new substring 's' containing the characters from the start
  of the string up to the newline character.
  Updates original string '*temp' then returns 's'. */

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

/*Read_file: Reads the contents of a file 'fd' and appends the read data
 to a given string 'temp' in chunks of 'BUFFER_SIZE' using a temporary 
 buffer 'buffer'. It stops reading when it encounters a newline char or
 reaches the end of the file. */

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

/*Get_next_line:*/
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
