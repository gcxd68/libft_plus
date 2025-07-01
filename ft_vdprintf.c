/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:36:03 by marvin            #+#    #+#             */
/*   Updated: 2025/06/25 17:36:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_write_buffer_fd(char *buffer, int count, int fd)
{
	int	written;

	written = write(fd, buffer, count);
	if (written < 0)
		return (-1);
	return (count);
}

static int	ft_write_chunks_fd(char *full_str, int total_len, int fd)
{
	char	buffer[PRINTF_BUFFER_SIZE];
	int		written;
	int		count;
	size_t	offset;
	size_t	chunk_size;

	count = 0;
	offset = 0;
	while (offset < (size_t)total_len)
	{
		if ((size_t)total_len - offset > sizeof(buffer))
			chunk_size = sizeof(buffer);
		else
			chunk_size = (size_t)total_len - offset;
		ft_memcpy(buffer, full_str + offset, chunk_size);
		written = write(fd, buffer, chunk_size);
		if (written < 0)
			return (-1);
		count += written;
		offset += chunk_size;
	}
	return (count);
}

static int	ft_format_large_fd(const char *format,
											va_list args, int total_len, int fd)
{
	char	*full_str;
	va_list	args_copy;
	int		count;

	full_str = malloc(total_len + 1);
	if (!full_str)
		return (-1);
	va_copy(args_copy, args);
	ft_vsnprintf(full_str, total_len + 1, format, args_copy);
	va_end(args_copy);
	count = ft_write_chunks_fd(full_str, total_len, fd);
	free(full_str);
	return (count);
}

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	char	buffer[PRINTF_BUFFER_SIZE];
	va_list	args_copy;
	int		total_len;
	int		count;

	va_copy(args_copy, args);
	total_len = ft_vsnprintf(buffer, sizeof(buffer), format, args_copy);
	va_end(args_copy);
	if (total_len < 0)
		return (total_len);
	if ((size_t)total_len < sizeof(buffer))
		count = ft_write_buffer_fd(buffer, total_len, fd);
	else
		count = ft_format_large_fd(format, args, total_len, fd);
	return (count);
}
