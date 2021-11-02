/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:17:35 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/02 18:01:00 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
size_t	ft_puthexa_lower(int nbr, size_t count);
size_t	ft_puthexa_upper(int nbr, size_t count);
void	ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_putnbr(int n, size_t count);
size_t	ft_putnbr_unsigned(unsigned int n, size_t count);
int		ft_printf(const char *printed, ...);

#endif
