/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynarr_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:59:08 by gdosch            #+#    #+#             */
/*   Updated: 2025/04/06 11:59:10 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dynarr_init(size_t elem_size, size_t capacity)
{
	t_dynarr	*info;

	if (capacity <= 0)
		capacity = 8;
	info = malloc(sizeof(t_dynarr) + elem_size * capacity);
	if (!info)
		return (NULL);
	info->size = 0;
	info->capacity = capacity;
	info->elem_size = elem_size;
	return ((void *)(info + 1));
}
