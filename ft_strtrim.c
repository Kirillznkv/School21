/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:15:35 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/01 20:27:30 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*del;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str = (char*)ft_calloc(ft_strlen(s1) + 1, 1);
	if (str)
	{
		ft_strlcat(str, s1, ft_strlen(s1));
		del = ft_strstr(str, set);
		ft_strlcpy(del, del + ft_strlen(set), ft_strlen(s1));
		del = ft_strrstr(str, set);
		ft_strlcpy(del, del + ft_strlen(set), ft_strlen(s1));
	}
	return (str);
}
