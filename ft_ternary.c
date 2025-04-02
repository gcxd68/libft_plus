/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:53:31 by gdosch            #+#    #+#             */
/*   Updated: 2025/04/02 17:04:01 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Usage example : int res = *(int *)ft_ternary(res < 0, &(int){0}, &res);

void	*ft_ternary(bool condition, void *true_val, void *false_val)
{
	if (condition)
		return (true_val);
	return (false_val);
}
