/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:10:40 by lyaiche           #+#    #+#             */
/*   Updated: 2021/10/21 17:52:58 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		a;
	char	written;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		a = -n;
	}
	else
		a = n;
	if (a > 9)
	{
		ft_putnbr_fd (a / 10, fd);
		a %= 10;
	}
	written = a + '0';
	write(fd, &written, 1);
}
