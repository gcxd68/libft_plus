/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynarr_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:52:33 by gdosch            #+#    #+#             */
/*   Updated: 2025/04/06 11:52:34 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_dynarr	*ft_dynarr_get_info(void *arr)
{
	if (!arr)
		return (NULL);
	return ((t_dynarr *)arr - 1);
}

static void	*ft_dynarr_reduce_capacity(void **arr_ptr)
{
	t_dynarr	*info;
	t_dynarr	*new_info;
	size_t		new_capacity;

	if (!arr_ptr || !*arr_ptr)
		return (NULL);
	info = ft_dynarr_get_info(*arr_ptr);
	if (info->size < info->capacity / 4 && info->capacity > 8)
	{
		new_capacity = info->capacity / 2;
		if (new_capacity < 8)
			new_capacity = 8;
		new_info = ft_realloc(info, sizeof(t_dynarr)
				+ info->elem_size * info->capacity, sizeof(t_dynarr)
				+ info->elem_size * new_capacity);
		if (new_info)
		{
			new_info->capacity = new_capacity;
			*arr_ptr = (void *)(new_info + 1);
		}
	}
	return (*arr_ptr);
}

void	ft_dynarr_remove(void **arr_ptr, size_t index)
{
	t_dynarr	*info;
	void		*arr;

	if (!arr_ptr || !*arr_ptr)
		return ;
	info = ft_dynarr_get_info(*arr_ptr);
	if (!info || index >= info->size)
		return ;
	arr = *arr_ptr;
	ft_memmove((char *)arr + index * info->elem_size,
		(char *)arr + (index + 1) * info->elem_size,
		(info->size - index - 1) * info->elem_size);
	info->size--;
	if (!ft_dynarr_reduce_capacity((void **)arr_ptr))
		return ;
}
