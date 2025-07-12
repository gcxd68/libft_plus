/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:15:45 by gdosch            #+#    #+#             */
/*   Updated: 2024/11/18 15:15:47 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_build_line(char **line, char **buffer, size_t *len)
{
	char			*tmp;
	size_t			chunk_len;
	size_t			i;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	chunk_len = i + ((*buffer)[i] == '\n');
	tmp = ft_realloc(*line, *len + 1, *len + chunk_len + 1);
	if (!tmp)
		return (-1);
	*line = tmp;
	ft_strlcpy(*line + *len, *buffer, chunk_len + 1);
	*len += chunk_len;
	return (i);
}

static ssize_t	ft_parse_data(int fd, char *buffer, char **line, size_t *len)
{
	ssize_t	ret;

	if (!*buffer)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret <= 0)
			return (ret);
		buffer[ret] = '\0';
	}
	ret = ft_build_line(line, &buffer, len);
	if (ret < 0)
		return (-2);
	if (buffer[ret] == '\0')
		return (((*buffer) = '\0'), 1);
	ft_memcpy(buffer, buffer + ret + 1, ft_strlen(buffer) - ret);
	return (0);
}

ssize_t	safe_gnl(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			ret;
	size_t		len;

	if (fd < 0)
		return (-3);
	if (BUFFER_SIZE < 1)
		return (-4);
	*line = ft_calloc(1, 1);
	if (!*line)
		return (-1);
	len = 0;
	ret = 1;
	while (ret > 0)
		ret = ft_parse_data(fd, buffer, line, &len);
	if (ret < 0 || !len)
		return (free(*line), *line = 0, ret);
	return (len);
}
