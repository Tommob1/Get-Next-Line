/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:25:41 by btomlins          #+#    #+#             */
/*   Updated: 2023/04/06 13:45:30 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*out;
	static char	*buffcpy[OPEN_LIMIT];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_LIMIT)
		return (0);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	if (!buffcpy[fd])
		buffcpy[fd] = ft_strdup("");

}
