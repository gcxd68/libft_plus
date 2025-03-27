/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:50:13 by gdosch            #+#    #+#             */
/*   Updated: 2025/02/03 09:50:15 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_arr_get(const int *arr, size_t size, size_t idx, int def_value)
{
	if (idx >= size)
	{
		if ((unsigned long)size <= (unsigned long)UINT_MAX)
			ft_dprintf(2,
				"Error: out-of-bounds access at index %u (max size: %u)\n",
				(unsigned)idx, (unsigned)(size - 1));
		else if ((unsigned long)idx <= (unsigned long)UINT_MAX)
			ft_dprintf(2, "Error: out-of-bounds access at index %u\n",
				(unsigned)idx);
		else
			ft_dprintf(2, "Error: out-of-bounds access");
		return (def_value);
	}
	return (arr[idx]);
}
