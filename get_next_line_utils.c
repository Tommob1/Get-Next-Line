/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:26:49 by btomlins          #+#    #+#             */
/*   Updated: 2023/04/06 13:45:12 by btomlins         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = NULL;
	if (!s1 || !s2)
		return (0);
	else
	{
		str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
		if (!str)
			return (0);
		ft_strlcpy(str, s1, s1_len + 1);
		ft_strlcpy(str + (s1_len), s2, s2_len + 1);
	}
	return (str);
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
