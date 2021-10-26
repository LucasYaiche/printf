/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasyaiche <lucasyaiche@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:25:18 by lyaiche           #+#    #+#             */
/*   Updated: 2021/10/19 13:50:42 by lucasyaiche      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src2;
	unsigned char	*dest2;

	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (!src2 && !dest2)
		return (NULL);
	if ((src2 < dest2) && dest2 < src2 + n)
	{
		src2 += n;
		dest2 += n;
		while (n--)
			*--dest2 = *--src2;
	}
	else
	{
		while (n--)
			*dest2++ = *src2++;
	}
	return (dest);
}
