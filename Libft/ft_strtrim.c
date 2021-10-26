/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:36:43 by lyaiche           #+#    #+#             */
/*   Updated: 2021/10/25 13:43:47 by lyaiche          ###   ########.fr       */
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

static int	ft_check(char s, char const *set)
{
	while (*set)
	{
		if (s == *set++)
			return (1);
	}
	return (0);
}

static void	putstr(char *start, char *answer, size_t i, size_t j)
{
	while (i <= j)
	{
		*answer++ = *start++;
		i++;
	}
	*answer++ = '\0';
}

static size_t	find_end(char const *str, char const *set)
{
	size_t	j;

	j = 0;
	while (str[j])
		j++;
	j -= 1;
	while (ft_check(str[j], set))
		j--;
	return (j);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*answer;
	char	*start;
	size_t	i;
	size_t	j;

	if (!str || !set)
		return (NULL);
	start = (char *)str;
	i = -1;
	while (str[++i])
	{
		if (!(ft_check(str[i], set)))
			break ;
		start++;
	}
	if (i == ft_strlen(str))
		return (ft_strdup(""));
	j = find_end(str, set);
	answer = get(j - i + 1);
	if (!answer)
		return (NULL);
	putstr(start, answer, i, j);
	return (answer);
}
