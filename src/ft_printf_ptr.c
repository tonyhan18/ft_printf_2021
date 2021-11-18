/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:07:40 by chahan            #+#    #+#             */
/*   Updated: 2021/11/18 21:07:47 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_ptr_len(unsigned long long ptr)
{
	int printf_len;

	printf_len = 0;
	while (ptr > 0)
	{
		printf_len++;
		ptr /= 16;
	}
	return (printf_len);
}

void ft_putPtr(unsigned long long ptr)
{
	if(ptr >= 16)
	{
		ft_putPtr(ptr / 16);
		ft_putPtr(ptr % 16);
	}
	else
	{
		if (ptr < 10)
		{
			ft_putchar_fd('0' + ptr, 1);
		}
		else
		{
			ft_putchar_fd(ptr - 10 + 'a', 1);
		}
	}
}

int ft_printPtr(unsigned long long ptr)
{
	int printf_len;

	printf_len = 0;
	printf_len += write(1, "0x", 2);
	if(ptr == 0)
	{
		printf_len += write(1, "0", 1);
	}
	else
	{
		ft_putPtr(ptr);
		printf_len += ft_ptr_len(ptr);
	}
	return (printf_len);
}