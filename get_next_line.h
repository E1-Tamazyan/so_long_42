/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:06:43 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/04 16:01:10 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_readfd(int fd, char *buffer);
char	*ft_filtr(char	*buffer);
char	*ft_strdup(char *s1, int dir);
size_t	ft_strlen(const char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);

#endif
