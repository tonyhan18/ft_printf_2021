/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:52:02 by chahan            #+#    #+#             */
/*   Updated: 2021/11/15 00:52:04 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printChar(int c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_formats(va_list args, const char format)
{
	int	printf_len;

	printf_len = 0;
	if(format == 'c')
		printf_len += ft_printChar(va_arg(args, int));
	else if (format == 's')
		printf_len += ft_printStr(va_arg(args, char *));
	else if (format == 'p')
		printf_len += ft_printPtr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		printf_len += ft_printNbr(va_arg(args, int));
	else if (format == 'u')
		printf_len += ft_printf_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		printf_len += ft_printHex(va_arg(args, unsigned int), format);
	else if (format == '%')
		printf_len += ft_printPercent();
	return (printf_len);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int i;
	int printf_len;

	i = 0;
	printf_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printf_len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
		{
			printf_len += ft_printChar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (printf_len);
}
