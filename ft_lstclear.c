/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:53:35 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/03 16:58:22 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*pl;

	new_lst = *lst;
	while (new_lst)
	{
		pl = new_lst->next;
		ft_lstdelone(new_lst, del);
		new_lst = pl;
	}
}
