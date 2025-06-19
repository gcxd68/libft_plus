/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:45:49 by gdosch            #+#    #+#             */
/*   Updated: 2025/05/13 13:45:50 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putstr_ct(const char *s, char *str)
{
	int	count;

	count = 0;
	if (!s)
	{
		ft_memcpy(str, "(null)", 6);
		str += 6;
		return (6);
	}
	while (s[count])
	{
		*(str)++ = s[count];
		count++;
	}
	return (count);
}

static int	ft_putnbr_ct(unsigned long n, char format, char *str)
{
	char	*base;
	int		base_len;
	int		count;

	count = 0;
	if (format == 'p' || format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	base_len = ft_strlen(base);
	if ((format == 'd' || format == 'i') && (long)n < 0)
	{
		*str = '-';
		count++;
		n = -(long)n;
	}
	if (n >= (unsigned long)base_len)
		count += ft_putnbr_ct(n / base_len, format, str + count);
	str[count] = base[n % base_len];
	return (++count);
}

static int	ft_putptr_ct(const void *p, char *str)
{
	int	count;

	if (!p)
	{
		ft_memcpy(str, "(nil)", 5);
		return (5);
	}
	ft_memcpy(str, "0x", 2);
	count = ft_putnbr_ct((unsigned long)p, 'p', str + 2);
	return (count + 2);
}

static int	ft_format(const char format, va_list args, char *str, size_t size)
{
	int	count;

	count = 0;
	if ((size_t)count < size)
	{
		if (format == 'c')
			(str)[count++] = (char)va_arg(args, int);
		else if (format == 's')
			count += ft_putstr_ct(va_arg(args, const char *), str);
		else if (format == 'p')
			count += ft_putptr_ct(va_arg(args, const void *), str);
		else if (format == 'd' || format == 'i')
			count += ft_putnbr_ct((long)va_arg(args, int), format, str);
		else if (format == 'u')
			count += ft_putnbr_ct(va_arg(args, unsigned int), format, str);
		else if (format == 'x')
			count += ft_putnbr_ct(va_arg(args, unsigned int), format, str);
		else if (format == 'X')
			count += ft_putnbr_ct(va_arg(args, unsigned int), format, str);
		else if (format == '%')
			(str)[count++] = '%';
	}
	return (count);
}

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list args)
{
	int		count;

	if (!format)
		return (-1);
	count = 0;
	while (*format && (size_t)count < size - 1)
	{
		if (*format == '%' && *(format + 1) == '\0')
			return (-1);
		if (*format == '%')
			count += ft_format(*(++format), args, str + count, size - count);
		else
			str[count++] = *format;
		format++;
	}
	str[count] = '\0';
	return (count);
}
