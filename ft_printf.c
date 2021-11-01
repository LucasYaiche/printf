/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasyaiche <lucasyaiche@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:28:23 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/01 19:50:33 by lucasyaiche      ###   ########.fr       */
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
				ft_putchar_fd(*current_var, 1);
			}
			else if (printed[i] == 's')
			{
				current_var = va_arg(args, char *);
				ft_putstr_fd(current_var, 1);
			}
		}
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	char	*prenom;
	char	*nom;

	prenom = "Lucas";
	nom = "Yaiche";
	ft_printf("Je m'appelle %s %s", prenom, nom);
	//printf("Je m'appelle %s %s", prenom, nom);
	//printf("test");
	return (0);
}
