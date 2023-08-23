/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:51:34 by dabdygal          #+#    #+#             */
/*   Updated: 2023/08/23 14:49:19 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# ifdef BUFFER_SIZE
#  if BUFFER_SIZE > 1000000
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 4096
#  endif
# else
#  define BUFFER_SIZE 4096
# endif

char	*get_next_line(int fd);
int		cut_n_chars(char **str, ssize_t n, ssize_t len);

#endif
