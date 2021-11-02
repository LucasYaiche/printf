/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:37:12 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/02 17:40:07 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthexa_upper(int nbr, size_t count)
{
	unsigned int	i;
	long long		nb;
	char			*base;

	base = "0123456789ABCDEF";
	i = 0;
	nb = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		count++;
		nb *= -1;
	}
	while (base[i])
		i++;
	if (nb >= i)
		count = ft_puthexa_upper(nb / i, count);
	ft_putchar(base[nb % i]);
	return (count);
}
