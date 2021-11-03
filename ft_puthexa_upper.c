/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:37:12 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/03 14:23:21 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthexa_upper(unsigned long nbr, size_t count)
{
	count++;
	if (nbr > 9 && nbr < 16)
	{
		if (nbr == 10)
			ft_putchar('A');
		else if (nbr == 11)
			ft_putchar('B');
		else if (nbr == 12)
			ft_putchar('C');
		else if (nbr == 13)
			ft_putchar('D');
		else if (nbr == 14)
			ft_putchar('E');
		else if (nbr == 15)
			ft_putchar('F');
	}
	else if (nbr > 15)
	{
		count = ft_puthexa_upper(nbr / 16, count);
		ft_puthexa_upper(nbr % 16, count);
	}
	else
		ft_putchar(nbr + 48);
	return (count);
}
