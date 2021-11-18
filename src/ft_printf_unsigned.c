/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ungisned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:35:42 by chahan            #+#    #+#             */
/*   Updated: 2021/11/18 21:35:43 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_unsigned_len(unsigned int n)
{
	int	printf_len;

	printf_len = 0;
	while (n > 0)
	{
		printf_len++;
		n /= 10;
	}
	return (printf_len);
}

char	*uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_unsigned_len(n);
	num = (char *)malloc(sizeof(char) * n);
	if (!num)
		return (0);
	num[len] = '\0';
	while (n > 0)
	{
		num[len] = (n % 10 + '0');
		n = n / 10;
		len--;
	}
	return (num);
}

int		ft_printf_unsigned(unsigned int n)
{
	int		printf_len;
	char	*num;

	printf_len = 0;
	if (n == 0)
	{
		printf_len += write(1, "0", 1);
	}
	else
	{
		num = uitoa(n);
		printf_len += ft_printStr(num);
		free(num);
	}
	return (printf_len);
}
