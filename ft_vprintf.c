/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:41:20 by gdosch            #+#    #+#             */
/*   Updated: 2025/06/25 17:37:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vprintf(const char *format, va_list args)
{
	const int	ret = ft_vdprintf(STDOUT_FILENO, format, args);

	return (ret);
}
