/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:51:58 by chahan            #+#    #+#             */
/*   Updated: 2021/11/17 20:51:59 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_putStr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printStr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putStr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printNbr(int num)
{
	int		printf_len;
	char	*str;

	printf_len = 0;
	str = ft_itoa(num);
	printf_len = ft_printStr(str);
	free(str);
	return (printf_len);
}

int	ft_printPercent(void)
{
	write(1, "%", 1);
	return (1);
}
