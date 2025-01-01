/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcemirayalgan <tugcemirayalgan@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:14:44 by tukaraca          #+#    #+#             */
/*   Updated: 2025/01/02 01:24:22 by tugcemiraya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_last_line(char *str)
{
	char	*final;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free (str), NULL);
	if (str[i] == '\n')
		i++;
	final = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!final)
		return (free(str), NULL);
	while (str[i])
		final[j++] = str[i++];
	final[j] = '\0';
	free(str);
	return (final);
}

char	*get_read(int fd, char *str)
{
	char	*buff;
	int		rd;

	rd = 1;
	if (!str)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (rd != 0 && !ft_strchr(str, '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (free(str), free(buff), NULL);
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_first_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i] != '\0' && str[i] != '\n')
		line[i] = str[i];
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[1042];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = get_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_first_line(str[fd]);
	str[fd] = get_last_line(str[fd]);
	return (line);
}