/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynarr_from.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:57:04 by gdosch            #+#    #+#             */
/*   Updated: 2025/04/06 11:57:06 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_dynarr	*ft_dynarr_get_info(void *arr)
{
	if (!arr)
		return (NULL);
	return ((t_dynarr *)arr - 1);
}

void	*ft_dynarr_from(void *static_arr, size_t elem_size, size_t count)
{
	void		*arr;
	t_dynarr	*info;

	arr = ft_dynarr_init(elem_size, count);
	if (!arr || !static_arr)
		return (arr);
	info = ft_dynarr_get_info(arr);
	ft_memcpy(arr, static_arr, count * elem_size);
	info->size = count;
	return (arr);
}
