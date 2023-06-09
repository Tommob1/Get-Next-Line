/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btomlins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:27:22 by btomlins          #+#    #+#             */
/*   Updated: 2023/04/21 15:50:52 by btomlins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*'ifndef' acts as a guard to ensure the macros have not yet been defined.
 If they haven't been defined, the code below the guards will run. */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/*OPEN_LIMIT represents the maximum number of open file descriptors*/

# ifndef OPEN_LIMIT
#  define OPEN_LIMIT 254
# endif

char	*get_next_line(int fd);

/* UTIL FUNCTS prototypes, referenced from get_next_line_utils.c,
   to be used in main.*/
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free(char *temp, const char *buf);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
