/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 03:42:18 by lucasyaiche       #+#    #+#             */
/*   Updated: 2021/10/25 12:57:29 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*link;

	if (!lst || !f)
		return (NULL);
	link = ft_lstnew(f(lst->content));
	if (!link)
		return (NULL);
	lst2 = link;
	lst = lst->next;
	while (lst)
	{
		link = ft_lstnew(f(lst->content));
		if (!link)
		{
			ft_lstclear(&lst2, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&lst2, link);
	}
	return (lst2);
}
