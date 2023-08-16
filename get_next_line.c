/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:49:33 by dabdygal          #+#    #+#             */
/*   Updated: 2023/08/16 11:28:25 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#ifdef BUFFER_SIZE
# if BUFFER_SIZE > 4096
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
#else
# define BUFFER_SIZE 4096
#endif

ssize_t	read_until_eol(char **output, int fd)
{
	ssize_t	bytes_read;
	ssize_t	len;
	char	*buf;

	bytes_read = 1;
	len = 0;
	buf = (char *) ft_calloc(1, BUFFER_SIZE);
	if (!buf)
		return (-1);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		len += bytes_read;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buf;
	ssize_t			len;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buf)
		len = read_until_eol(&buf, fd);
	if (len < 0)
		return (NULL);
	return (line);
}
