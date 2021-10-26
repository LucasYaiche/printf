/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:31:20 by lyaiche           #+#    #+#             */
/*   Updated: 2021/10/21 13:09:44 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char c, char compared)
{
	if (c == compared)
		return (1);
	return (0);
}

static char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	count(char const *str, char compared)
{
	int	i;
	int	word_len;
	int	nbr_words;

	i = 0;
	nbr_words = 0;
	while (str[i])
	{
		while (str[i] && check_char(str[i], compared))
			i++;
		word_len = 0;
		while (str[i + word_len] && !check_char(str[i + word_len], compared))
			word_len++;
		if (word_len)
			nbr_words++;
		i += word_len;
	}
	return (nbr_words);
}

static char	**fill_matrix(char const *str, char compared, char **result,
	unsigned int nbr_words)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	word_len;

	i = 0;
	j = 0;
	while (i < nbr_words)
	{
		while (str[j] && check_char(str[j], compared))
			j++;
		word_len = 0;
		while (str[j + word_len] && !check_char(str[j + word_len], compared))
			word_len++;
		result[i] = malloc(sizeof(char) * (word_len + 1));
		if (!result[i])
		{
			while (result[i])
				free(result[--i]);
			return (NULL);
		}
		ft_strncpy(result[i], &str[j], word_len);
		j += word_len;
		i++;
	}
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char			**result;
	unsigned int	nb_words;

	if (!s)
		return (NULL);
	nb_words = count(s, c);
	result = malloc(sizeof(char *) * (nb_words + 1));
	if (!result)
		return (NULL);
	result = fill_matrix(s, c, result, nb_words);
	result[nb_words] = 0;
	return (result);
}
