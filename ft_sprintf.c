/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:45:48 by gdosch            #+#    #+#             */
/*   Updated: 2025/06/25 17:38:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_vsprintf(str, format, args);
	va_end(args);
	return (count);
}
