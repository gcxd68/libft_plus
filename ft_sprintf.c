/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:07:33 by gdosch            #+#    #+#             */
/*   Updated: 2025/04/10 16:07:34 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putstr_ct(const char *s, char **str)
{
	int	count;

	count = 0;
	if (!s)
	{
		ft_memcpy(*str, "(null)", 6);
		*str += 6;
		return (6);
	}
	while (s[count])
	{
		*(*str)++ = s[count];
		count++;
	}
	return (count);
}

static int	ft_putnbr_ct(unsigned long n, char format, char *base, char **str)
{
	int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if ((format == 'd' || format == 'i') && (long)n < 0)
	{
		*(*str)++ = '-';
		count++;
		n = -(long)n;
	}
	if (n >= (unsigned long)base_len)
		count += ft_putnbr_ct(n / base_len, format, base, str);
	*(*str)++ = base[n % base_len];
	count++;
	return (count);
}

static int	ft_putptr_ct(const void *p, char **str)
{
	int	count;

	if (!p)
	{
		ft_memcpy(*str, "(nil)", 5);
		*str += 5;
		return (5);
	}
	ft_memcpy(*str, "0x", 2);
	*str += 2;
	count = ft_putnbr_ct((unsigned long)p, 'p', "0123456789abcdef", str);
	return (count + 2);
}

static void	ft_format(const char format, va_list args, char **str, int *count)
{
	char	*tmp;

	tmp = *str + *count;
	if (format == 'c')
		(*str)[(*count)++] = (char)va_arg(args, int);
	else if (format == 's')
		*count += ft_putstr_ct(va_arg(args, const char *), &tmp);
	else if (format == 'p')
		*count += ft_putptr_ct(va_arg(args, const void *), &tmp);
	else if (format == 'd' || format == 'i')
		*count += ft_putnbr_ct((long)va_arg(args, int),
				format, "0123456789", &tmp);
	else if (format == 'u')
		*count += ft_putnbr_ct(va_arg(args, unsigned int),
				format, "0123456789", &tmp);
	else if (format == 'x')
		*count += ft_putnbr_ct(va_arg(args, unsigned int),
				format, "0123456789abcdef", &tmp);
	else if (format == 'X')
		*count += ft_putnbr_ct(va_arg(args, unsigned int),
				format, "0123456789ABCDEF", &tmp);
	else if (format == '%')
		(*str)[(*count)++] = '%';
}

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '\0')
		{
			va_end(args);
			return (-1);
		}
		if (*format == '%')
			ft_format(*(++format), args, &str, &count);
		else
			str[count++] = *format;
		format++;
	}
	str[count] = '\0';
	va_end(args);
	return (count);
}
