/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:52:45 by chahan            #+#    #+#             */
/*   Updated: 2021/11/15 00:52:45 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printChar(int c);
int		ft_formats(va_list args, const char format);
int		ft_printf(const char *str, ...);

void	ft_putStr(char *str);
int		ft_printStr(char *str);
int		ft_printNbr(int num);
int		ft_printPercent(void);

int	ft_unsigned_len(unsigned int n);
char	*uitoa(unsigned int n);
int	ft_printf_unsigned(unsigned int n);

int	ft_ptr_len(unsigned long long ptr);
void	ft_putPtr(unsigned long long ptr);
int	ft_printPtr(unsigned long long ptr);

int	ft_hex_len(unsigned int n);
void	ft_putHex(unsigned int n, const char format);
int	ft_printHex(unsigned int n, const char format);

#endif