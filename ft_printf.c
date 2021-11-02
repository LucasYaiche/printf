/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:28:23 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/02 18:32:48 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *printed, ...)
{
	va_list			args;
	long int		current_int;
	char			*current_char;
	size_t			i;
	unsigned int	current_unsigned_int;
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
		{
			i++;
			if (printed[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (printed[i] == 'c')
			{
				current_int = va_arg(args, int);
				ft_putchar(current_int);
				count++;
			}
			else if (printed[i] == 's')
			{
				current_char = va_arg(args, char *);
				count += ft_putstr(current_char);
			}
			else if (printed[i] == 'd' || printed[i] == 'i')
			{
				current_int = va_arg(args, int);
				count += ft_putnbr(current_int, 0);
			}
			else if (printed[i] == 'u')
			{
				current_unsigned_int = va_arg(args, unsigned int);
				count += ft_putnbr_unsigned(current_unsigned_int, 0);
			}
			else if (printed[i] == 'x' || printed[i] == 'X')
			{
				current_int = va_arg(args, int);
				if (printed[i] == 'x')
					count += ft_puthexa_lower(current_int, 0);
				else
					count += ft_puthexa_upper(current_int, 0);
			}
			else if (printed[i] == 'p')
			{
				current_int = va_arg(args, int);
				ft_putstr("0x");
				count += 2;
				count += ft_puthexa_lower(current_int, 0);
			}
		}
	}
	va_end(args);
	return (count);
}


int	main(void)
{
	char			*prenom;
	char			*nom;
	void			*exemple;
	unsigned int	nbr;

	prenom = "Lucas";
	nom = "Yaiche";
	nbr = 10;
	exemple = nom;
	//ft_printf("Je m'appelle %s %s \n", prenom, nom);
	//printf("Je m'appelle %s %s \n", prenom, nom);
	//ft_printf("%d\n", ft_printf("%x || %p\n", nbr, exemple));
	//printf("%d\n", printf("%x || %p\n", nbr, exemple));
	ft_printf(" %x ", -1);
	printf(" %x ", -1);
	return (0);
}
