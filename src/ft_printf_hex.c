/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:51:10 by chahan            #+#    #+#             */
/*   Updated: 2021/11/18 20:51:12 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_hex_len(unsigned int n)
{
	int print_len;

	print_len = 0;
	while (n > 0)
	{
		print_len++;
		n /= 16;
	}
	return (print_len);
}

void ft_putHex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_putHex(n / 16, format);
		ft_putHex(n % 16, format);
	} else
	{
		if (n >= 10)
		{
			if (format == 'x')
				ft_putchar_fd(n - 10 + 'a', 1);
			else if(format == 'X')
				ft_putchar_fd(n - 10+ 'A', 1);
		}
		else
		{
			ft_putchar_fd(n + '0',1);
		}
	}
}

int ft_printHex(unsigned int n, const char format)
{
	if(n == 0)
		write(1,"0",1);
	else
		ft_putHex(n, format);
	return ft_hex_len(n);
}