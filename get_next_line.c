/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_Next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcemirayalgan <tugcemirayalgan@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:23:09 by tugcemiraya       #+#    #+#             */
/*   Updated: 2024/12/23 20:57:16 by tugcemiraya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	char	*final;
	int 	i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n') 
		i++;
	if(!str[i])
	{
		free(str);
		return (NULL);
	}
	final = (char *)malloc(sizeof(char) * ft_strlen(str) - i);
	if(!final)
		return (NULL);
	i++;
	while(str[i + j] != '\0')
	{
		final[j] = str[j + i];
		j++;
	}
	final[j] = '\0';
	free(str);
	return(final);
}

char	get_read(int fd, char *str)
{
	char *buff;
	int rd;

	rd = 1;
	buff = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(str, '\n') && rd != 0)
	{ 
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == _1)
		{
			free(buff);
			free(str);
			return(NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char get_last_line(char *str)
{
	char	*line;
	int		i;
	
	i = 0;
	if(!str[i])
		return(NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if(!line)
		return (NULL);
	i = 0;
	while(str[i] != '\0' && str[i] != '\n')
	{
		line[i]= str[i];
		i++;
	}
	if( str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}


char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_read(fd, str);
	if (!str) 
	{
		return (NULL); 
	}
	line = ft_liner(str);
	str = get_line(str);
	return (line);
}