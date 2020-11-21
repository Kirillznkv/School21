/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:11:40 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/02 18:23:23 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = -1;
	if (s == NULL)
		return (NULL);
	str = (char*)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (str)
		while (s[++i])
			str[i] = f(i, s[i]);
	return (str);
}
