/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:41:20 by gdosch            #+#    #+#             */
/*   Updated: 2025/05/13 14:41:22 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_write_buffer(char *buffer, int total_len)
{
	int	written;

	written = write(STDOUT_FILENO, buffer, total_len);
	if (written < 0)
		return (-1);
	return (total_len);
}

static int	ft_write_chunks(char *full_str, int total_len)
{
	char	buffer[PRINTF_BUFFER_SIZE];
	int		written;
	int		total_written;
	size_t	offset;
	size_t	chunk_size;

	total_written = 0;
	offset = 0;
	while (offset < (size_t)total_len)
	{
		if ((size_t)total_len - offset > sizeof(buffer))
			chunk_size = sizeof(buffer);
		else
			chunk_size = (size_t)total_len - offset;
		ft_memcpy(buffer, full_str + offset, chunk_size);
		written = write(STDOUT_FILENO, buffer, chunk_size);
		if (written < 0)
			return (-1);
		total_written += written;
		offset += chunk_size;
	}
	return (total_written);
}

static int	ft_format_large(const char *format, va_list args, int total_len)
{
	char	*full_str;
	va_list	args_copy;
	int		result;

	full_str = malloc(total_len + 1);
	if (!full_str)
		return (-1);
	va_copy(args_copy, args);
	ft_vsnprintf(full_str, total_len + 1, format, args_copy);
	va_end(args_copy);
	result = ft_write_chunks(full_str, total_len);
	free(full_str);
	return (result);
}

int	ft_vprintf(const char *format, va_list args)
{
	char	buffer[PRINTF_BUFFER_SIZE];
	va_list	args_copy;
	int		total_len;

	va_copy(args_copy, args);
	total_len = ft_vsnprintf(buffer, sizeof(buffer), format, args_copy);
	va_end(args_copy);
	if (total_len < 0)
		return (total_len);
	if ((size_t)total_len < sizeof(buffer))
		return (ft_write_buffer(buffer, total_len));
	return (ft_format_large(format, args, total_len));
}
