/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:30:31 by lucasyaiche       #+#    #+#             */
/*   Updated: 2021/10/21 15:18:15 by lyaiche          ###   ########.fr       */
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

static size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	ft_putnbr(char *answer, int nb, size_t len)
{
	answer[get_len(nb)] = '\0';
	while (nb > 0)
	{
		answer[len--] = nb % 10 + '0';
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*answer;
	int		negative;
	char	*returned;

	negative = 1;
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		negative *= -1;
		n *= -1;
	}
	if (negative < 0)
		answer = get(get_len(n) + 1);
	else
		answer = get(get_len(n));
	if (!answer)
		return (NULL);
	returned = answer;
	if (negative < 0)
		*answer++ = '-';
	ft_putnbr(answer, n, get_len(n) - 1);
	return (returned);
}
