/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynarr_add_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:46:50 by gdosch            #+#    #+#             */
/*   Updated: 2025/04/06 11:46:51 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_dynarr	*ft_dynarr_get_info(void *arr)
{
	if (!arr)
		return (NULL);
	return ((t_dynarr *)arr - 1);
}

static size_t	ft_dynarr_size(void *arr)
{
	t_dynarr	*info;

	info = ft_dynarr_get_info(arr);
	if (!info)
		return (0);
	return (info->size);
}

static void	*ft_dynarr_ensure_capacity(void **arr_ptr)
{
	t_dynarr	*info;
	t_dynarr	*new_info;
	size_t		new_capacity;

	if (!arr_ptr || !*arr_ptr)
		return (NULL);
	info = ft_dynarr_get_info(*arr_ptr);
	if (info->size >= info->capacity)
	{
		new_capacity = info->capacity * 2;
		new_info = ft_realloc(info, sizeof(t_dynarr)
				+ info->elem_size * info->capacity, sizeof(t_dynarr)
				+ info->elem_size * new_capacity);
		if (!new_info)
			return (NULL);
		new_info->capacity = new_capacity;
		*arr_ptr = (void *)(new_info + 1);
	}
	info = ft_dynarr_get_info(*arr_ptr);
	info->size++;
	return (*arr_ptr);
}

void	*ft_dynarr_add_ptr(void ***arr, void *value)
{
	size_t	size;

	if (!arr)
		return (NULL);
	if (!*arr)
		*arr = ft_dynarr_init(sizeof(void *), 8);
	if (!*arr)
		return (NULL);
	if (!ft_dynarr_ensure_capacity((void **)arr))
		return (NULL);
	size = ft_dynarr_size(*arr);
	(*arr)[size - 1] = value;
	return (value);
}
