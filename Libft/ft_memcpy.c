/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:12:16 by lyaiche           #+#    #+#             */
/*   Updated: 2021/10/16 14:33:23 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src_copy;
	char		*dest_copy;

	src_copy = (char *) src;
	dest_copy = (char *) dest;
	if (dest == src)
		return (NULL);
	while (n > 0)
	{
		*(dest_copy++) = *(src_copy++);
		n--;
	}
	return (dest);
}
