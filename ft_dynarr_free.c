/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynarr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:54:33 by gdosch            #+#    #+#             */
/*   Updated: 2025/04/06 11:54:36 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_dynarr	*ft_dynarr_get_info(void *arr)
{
	if (!arr)
		return (NULL);
	return ((t_dynarr *)arr - 1);
}

void	ft_dynarr_free(void *arr)
{
	t_dynarr	*info;

	if (arr)
	{
		info = ft_dynarr_get_info(arr);
		free(info);
	}
}
