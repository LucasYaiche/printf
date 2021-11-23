/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:28:23 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/23 15:33:33 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_adress(unsigned long arg, int count)
{
	ft_putstr("0x");
	count += 2;
	count += ft_puthexa(arg, 0, 'p');
	return (count);
}

static int	ft_printf_2(va_list args, const char current, int count)
{
	if (current == '%')
	{
		write(1, "%", 1);
		count++;
	}
	else if (current == 'c')
	{
		ft_putchar(va_arg(args, int));
		count++;
	}
	else if (current == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (current == 'd' || current == 'i')
		count += ft_putnbr(va_arg(args, int), 0);
	else if (current == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned long), 0);
	else if (current == 'x' || current == 'X')
		count += ft_puthexa(va_arg(args, unsigned int),
				0, current);
	else if (current == 'p')
		count = print_adress(va_arg(args, unsigned long), count);
	return (count);
}

int	ft_printf(const char *printed, ...)
{
	va_list			args;
	size_t			i;
	int				count;

	i = -1;
	count = 0;
	va_start(args, printed);
	while (printed[++i])
	{
		if (printed[i] != '%')
		{
			write(1, &printed[i], 1);
			count++;
		}
		else
			count = ft_printf_2(args, printed[++i], count);
	}
	va_end(args);
	return (count);
}
