/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:28:54 by lyaiche           #+#    #+#             */
/*   Updated: 2021/10/21 13:15:16 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elements, size_t len)
{
	void	*tab;

	tab = malloc(elements * len);
	if (!tab)
		return (NULL);
	ft_bzero(tab, elements * len);
	return (tab);
}
