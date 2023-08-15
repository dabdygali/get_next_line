/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:49:33 by dabdygal          #+#    #+#             */
/*   Updated: 2023/08/14 11:27:32 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#ifdef BUFFER_SIZE
# if BUFFER_SIZE > 4096
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
#else
# define BUFFER_SIZE 4096
#endif

char	*get_next_line(int fd)
{
	char			*line;
	static void		*buf;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buf)
		buf = ft_calloc(1, sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	if (read(fd, buf, BUFFER_SIZE) < 0)
		return (NULL);
	return (line);
}
