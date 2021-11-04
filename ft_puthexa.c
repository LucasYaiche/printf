/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasyaiche <lucasyaiche@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:37:12 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/04 01:42:54 by lucasyaiche      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*wich_base(char n)
{
	if (n == 'x' || n == 'p')
		return ("abcdef");
	else
		return ("ABCDEF");
}

static void	ft_puthexa_2(unsigned long nbr, char *base)
{
	if (nbr == 10)
		ft_putchar(base[0]);
	else if (nbr == 11)
		ft_putchar(base[1]);
	else if (nbr == 12)
		ft_putchar(base[2]);
	else if (nbr == 13)
		ft_putchar(base[3]);
	else if (nbr == 14)
		ft_putchar(base[4]);
	else if (nbr == 15)
		ft_putchar(base[5]);
}

size_t	ft_puthexa(unsigned long nbr, size_t count, char n)
{
	char	*base;

	base = wich_base(n);
	count++;
	if (nbr > 9 && nbr < 16)
		ft_puthexa_2(nbr, base);
	else if (nbr > 15)
	{
		count = ft_puthexa(nbr / 16, count, n);
		ft_puthexa(nbr % 16, count, n);
	}
	else
		ft_putchar(nbr + 48);
	return (count);
}
