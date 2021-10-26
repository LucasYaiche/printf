/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:47:23 by lucasyaiche       #+#    #+#             */
/*   Updated: 2021/10/16 14:48:34 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*x;
	const unsigned char	*y;

	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	if (n != 0)
	{
		while (x && n && y && (*x == *y))
		{
			x++;
			y++;
			n--;
		}
	}
	if (n == 0)
		return (0);
	return (*x - *y);
}
