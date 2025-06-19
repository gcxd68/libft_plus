/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:47:55 by gdosch            #+#    #+#             */
/*   Updated: 2025/05/13 12:47:57 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vsprintf(char *str, const char *format, va_list args)
{
	int	count;

	count = ft_vsnprintf(str, SIZE_MAX, format, args);
	return (count);
}
