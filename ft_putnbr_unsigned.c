/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:21:13 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/02 17:10:19 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_unsigned(unsigned int n, size_t count)
{
	char	written;

	count++;
	if (n > 9)
	{
		count = ft_putnbr_unsigned (n / 10, count);
		n %= 10;
	}
	written = n + '0';
	write(1, &written, 1);
	return (count);
}
