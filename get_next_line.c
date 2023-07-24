/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:27:06 by dabdygal          #+#    #+#             */
/*   Updated: 2023/07/24 11:45:33 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#ifdef BUFFER_SIZE
# if BUFFER_SIZE > BUFSIZ
#  undef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif
#else
# define BUFFER_SIZE BUFSIZ
#endif

char	*get_next_line(int fd)
{
	static size_t	current;
	char			*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
}
