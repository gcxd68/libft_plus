/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:50:51 by gdosch            #+#    #+#             */
/*   Updated: 2025/02/22 12:50:52 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rand(int min, int max)
{
	static int	initialized = 0;
	int			temp;

	if (min > max)
	{
		temp = min;
		min = max;
		max = temp;
	}
	if (!initialized)
	{
		srand(time(NULL));
		initialized = 1;
	}
	return (min + rand() % (max - min + 1));
}
