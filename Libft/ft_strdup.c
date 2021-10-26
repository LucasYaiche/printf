/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:35:24 by lyaiche           #+#    #+#             */
/*   Updated: 2021/10/25 13:20:06 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get(size_t len)
{
	char	*str;

	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (0);
	return (str);
}

char	*ft_strdup(const char	*s)
{
	size_t			len;
	char			*s2;
	size_t			i;

	len = ft_strlen(s);
	i = 0;
	s2 = get(len);
	if (!s2)
		return (NULL);
	while (i <= len)
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}
