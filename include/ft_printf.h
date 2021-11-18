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

int ft_printChar(int);
int ft_formats(va_list , const char);
int ft_printf(const char *, ...);

void ft_putStr(char *);
int ft_printStr(char *);
int ft_printNbr(int);
int ft_printPercent(void);

int ft_unsigned_len(unsigned int);
char *uitoa(unsigned int);
int ft_printf_unsigned(unsigned int);

int ft_ptr_len(unsigned long long);
void ft_putPtr(unsigned long long);
int ft_printPtr(unsigned long long);

int ft_hex_len(unsigned int);
void ft_putHex(unsigned int, const char);
int ft_printHex(unsigned int, const char);
#endif