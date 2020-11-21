/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:26:30 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/01 15:02:32 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = -1;
	str = (char*)ft_calloc((ft_strlen((char*)s) + 1), sizeof(char));
	while (str && s[++i])
		str[i] = s[i];
	return (str);
}
