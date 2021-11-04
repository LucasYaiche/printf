/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasyaiche <lucasyaiche@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:17:35 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/04 02:48:30 by lucasyaiche      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_puthexa(unsigned long nbr, size_t count, char n);
void	ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_putnbr(int n, size_t count);
size_t	ft_putnbr_unsigned(unsigned int n, size_t count);
int		ft_printf(const char *printed, ...);

#endif
