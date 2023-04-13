/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:26:49 by btomlins          #+#    #+#             */
/*   Updated: 2023/04/13 10:15:51 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s || ((*s ++ '\0') && (c == '\0')))
	{
		if (((char)*s) == ((char)c))
			return ((char *) s);
		s++;
	}
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	a;
	size_t	b;
	size_t	strlen;

	strlen = ft_strlen(s);
	if (start > strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		len = strlen - start;
	a = 0;
	b = 0;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	while (s[a])
	{
		if (b < len && a >= start)
		{
			ptr[b++] = s[a];
		}
		a++;
	}
	ptr[b] = '\0';
	return (ptr);
}

char	*ft_strjoin_free(char *temp, const char *buf)
{
	char	*new_temp;
	char	*new_temp_ptr;
	char	*temp_ptr;

	new_temp = malloc((ft_strlen(temp) + ft_strlen(buf) + 1));
	if (!new_temp)
	{
		free (temp);
		return (0);
	}
	new_temp_ptr = new_temp;
	temp_ptr = temp;
	while (*temp_ptr)
		*new_temp_ptr++ = *temp_ptr++;
	while (*buf)
		*new_temp_ptr++ = *buf++;
	*new_temp_ptr = 0;
	free (temp);
	return (new_temp);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		s1_len;
	int		i;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	dest = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
