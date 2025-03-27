/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:06:23 by gdosch            #+#    #+#             */
/*   Updated: 2025/02/06 12:12:10 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base_is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!base || !*base || ft_strlen(base) == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= '\t' && base[i] <= '\r'))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_pos_in_base(int str_char, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str_char)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *nptr, char *base)
{
	unsigned long long	res;
	int					sign;

	sign = 1;
	res = 0;
	if (!nptr || !ft_base_is_valid(base))
		return (0);
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_pos_in_base(*nptr, base) != -1)
	{
		res = res * ft_strlen(base) + (ft_pos_in_base(*nptr, base));
		if (res > (unsigned long long)INT_MAX + (sign < 0))
			return (0);
		nptr++;
	}
	return ((int)res * sign);
}
