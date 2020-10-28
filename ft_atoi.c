/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:29:03 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/28 20:04:01 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_atoi(const char* str)
{
	size_t	res;
	size_t	n;

	res = 0;
	n = ft_strlen(str);
	while (n-- > 0)
		res = (res +str[n] - '0') * 10;
	return res / 10;
}

int			main()
{
	char c[]="3526462";
	printf("%zu\n", ft_atoi(c));
	return 0;
}
