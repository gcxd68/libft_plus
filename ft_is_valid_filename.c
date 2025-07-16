/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_filename.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:22:12 by gdosch            #+#    #+#             */
/*   Updated: 2025/07/16 13:22:13 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_valid_filename(const char *name, const char *ext)
{
	size_t	name_len;
	size_t	ext_len;

	if (!name || !*name || !ext || !*ext)
		return (false);
	name_len = ft_strlen(name);
	ext_len = ft_strlen(ext);
	if (name_len < ext_len + 2
		|| name[name_len - ext_len - 1] != '.'
		|| ft_strncmp(&name[name_len - ext_len], ext, ext_len)
		|| name[name_len - ext_len - 2] == '/')
		return (false);
	return (true);
}
