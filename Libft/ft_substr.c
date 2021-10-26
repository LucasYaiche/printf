/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:30:02 by lucasyaiche       #+#    #+#             */
/*   Updated: 2021/10/21 12:34:23 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get(size_t len)
{
	char	*returned;

	returned = malloc(sizeof(*returned) * (len + 1));
	if (!returned)
		return (0);
	return (returned);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*answer;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (ft_strlen(s) - 1 < start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start - 1 < len)
		len = ft_strlen(s) - start;
	answer = get(len);
	if (!answer || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			answer[j++] = s[i];
		i++;
	}
	answer[j] = 0;
	return (answer);
}
