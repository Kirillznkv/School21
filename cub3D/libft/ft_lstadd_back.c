/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:43:06 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/03 16:29:44 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pl;

	pl = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		if (new)
		{
			while (pl->next)
				pl = pl->next;
			pl->next = new;
		}
	}
}
