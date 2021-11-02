/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:37:12 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/02 18:57:12 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthexa_lower(int nbr, size_t count)
{
	unsigned int	i;
	long int		nb;
	char			*base;

	base = "0123456789abcdef";
	i = 0;
	nb = 4294967295;
	nb -= nbr;
	count = 8;
	/*
	if (nbr < 0)
	{
		ft_putchar('-');
		count++;
		nb *= -1;
	}
	*/
	while (base[i])
		i++;
	if (nb >= i)
		ft_puthexa_lower(nb / i, count);
	ft_putchar(base[nb % i]);
	return (count);
}

// complement a 2 