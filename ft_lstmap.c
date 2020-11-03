/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:13:46 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/03 15:33:15 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		size;
	t_list	*tmp;
	t_list	*beg_tmp;
	t_list	*beg_lst;

	if (lst == NULL)
		return (NULL);
	size = ft_lstsize(lst);
	if ((tmp = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	beg_tmp = tmp;
	while (--size)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(f(lst->content));
		if (tmp->next == NULL)
		{
			lst = beg_lst;
			ft_lstclear(beg_tmp, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	lst = beg_lst;
	return (beg_tmp);
}
