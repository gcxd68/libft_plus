/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:47:29 by gdosch            #+#    #+#             */
/*   Updated: 2025/05/13 13:47:31 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_vsnprintf(str, size, format, args);
	va_end(args);
	return (count);
}
