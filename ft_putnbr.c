/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:10:40 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/02 18:17:50 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(int n, size_t count)
{
	long int	a;
	char		written;

	count++;
	if (n < 0)
	{
		write(1, "-", 1);
		a = n;
		a *= -1;
		count++;
	}
	else
		a = n;
	if (a > 9)
	{
		count = ft_putnbr (a / 10, count);
		a %= 10;
	}
	written = a + '0';
	write(1, &written, 1);
	return (count);
}
