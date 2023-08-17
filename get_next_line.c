/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:49:33 by dabdygal          #+#    #+#             */
/*   Updated: 2023/08/17 16:51:54 by dabdygal         ###   ########.fr       */
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

static char	*cut_first_line(char **buf, ssize_t len)
{
	char	*line;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (i < len && (*buf)[i] != '\n')
		i++;
	if (i < len)
		i += 1;
	line = (char *) malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = (*buf)[j];
		j++;
	}
	line[j] = '\0';
	if (cut_n_chars(buf, i, len) < 0)
		return (NULL);
	return (line);
}

static void	*expand_cat(void *to_expand, size_t explen, void *s, size_t slen)
{
	char	*temp;
	size_t	i;

	temp = malloc(sizeof(char) * (explen + slen));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < explen)
	{
		((char *)temp)[i] = ((char *)to_expand)[i];
		i++;
	}
	while (i < explen + slen)
	{
		((char *)temp)[i] = ((char *)s)[i - explen];
		i++;
	}
	free(to_expand);
	return (temp);
}

static int	char_present_n(char *buf, char c, ssize_t size)
{
	ssize_t	i;

	if (!buf)
		return (0);
	i = 0;
	while (i < size)
	{
		if (buf[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static ssize_t	read_until_eol(void **batch, int fd)
{
	ssize_t	bytes_read;
	size_t	len;
	void	*buf;

	bytes_read = 0;
	len = 0;
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (-1);
	while (!char_present_n((char *) buf, '\n', bytes_read))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		if (bytes_read == 0)
			return (0);
		*batch = expand_cat(*batch, len, buf, bytes_read);
		if (!batch)
			return (-1);
		len += bytes_read;
	}
	free (buf);
	return (len);
}

char	*get_next_line(int fd)
{
	char			*line;
	static void		*buf;
	ssize_t			len;

	len = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buf)
	{
		len = read_until_eol(&buf, fd);
		if (len <= 0)
			return (NULL);
	}
	line = cut_first_line((char **) &buf, len);
	return (line);
}
