/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcemirayalgan <tugcemirayalgan@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:21:36 by tukaraca          #+#    #+#             */
/*   Updated: 2025/01/02 01:22:30 by tugcemiraya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
int		ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlcpy(char *dst, char *src, int size);
char	*get_line_first(char *str);
char	*get_read(int fd, char *str);
char	*get_last_line(char *str);
char	*get_next_line(int fd);

#endif
