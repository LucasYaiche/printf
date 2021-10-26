/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:58:16 by lyaiche           #+#    #+#             */
/*   Updated: 2021/10/20 16:37:36 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*answer;
	int		i;

	i = -1;
	if (!s || !f)
		return (0);
	answer = ft_strdup(s);
	if (!answer)
		return (NULL);
	while (answer[++i])
		answer[i] = f(i, answer[i]);
	return (answer);
}
