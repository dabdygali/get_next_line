/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:41:29 by dabdygal          #+#    #+#             */
/*   Updated: 2023/08/16 10:27:40 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (count >= INT_MAX && size >= INT_MAX)
		return (NULL);
	if (size == 0 || count == 0)
	{
		count = 1;
		size = 1;
	}
	if (count >= ((size_t) - 1) / size)
		return (NULL);
	total_size = count * size;
	ptr = (void *) malloc(total_size);
	if (!ptr)
		return (NULL);
	while (total_size)
	{
		total_size--;
		*(char *)(ptr + total_size) = 0;
	}
	return (ptr);
}
