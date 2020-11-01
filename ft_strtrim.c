/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:15:35 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/01 21:15:14 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*del;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str = (char*)ft_calloc(ft_strlen(s1) + 1, 1);
	if (ft_strlen(s1) < ft_strlen(set))
		return (str);
	if (str)
	{
		ft_strlcat(str, s1, ft_strlen(s1));
		while (*set)
		{
			del = ft_strstr(str, set);
			if (del)
				ft_strlcpy(del, del + 1, ft_strlen(s1));
			del = ft_strrstr(str, set);
			if (del)
				ft_strlcpy(del, del + 1, ft_strlen(s1));
			set++;
		}
	}
	return (str);
}
