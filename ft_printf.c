/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:28:23 by lyaiche           #+#    #+#             */
/*   Updated: 2021/10/30 16:28:38 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"

int	ft_printf(const char *printed, ...)
{
	va_list		args;
	char		*current_var;
	size_t		i;

	i = -1;
	va_start(args, printed);
	while (printed[++i])
	{
		if (printed[i] != '%')
			write(1, &printed[i], 1);
		else
		{
			i++;
			if (printed[i] == '%')
				write(1, "%", 1);
			else if (printed[i] == 'c')
			{
				current_var = va_arg(args, char *);
				write(1, &current_var, 1);
			}
			else if (printed[i] == 's')
			{
				current_var = va_arg(args, char *);
				while (*current_var)
				{
					write(1, &current_var, 1);
					current_var++;
				}
			}
		}
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	char	*nom;

	nom = "L";
	ft_printf("Je m'appelle %c", nom);
	return (0);
}
