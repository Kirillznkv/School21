/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:48:34 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/02 18:07:24 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			size_finder(int n)
{
	unsigned int	ln;
	int				res;

	ln = 0;
	res = 0;
	if (n < 0)
		res++;
	ln = n > 0 ? n : -n;
	if (n == 0)
		res++;
	while (ln > 0)
	{
		ln /= 10;
		res++;
	}
	return (res);
}

char				*ft_itoa(int n)
{
	unsigned int	ln;
	int				size;
	char			*str;

	ln = 0;
	size = size_finder(n);
	str = (char*)ft_calloc(size + 1, sizeof(char));
	if (str)
	{
		if (n == 0)
			str[0] = '0';
		if (n < 0)
			str[0] = '-';
		ln = n > 0 ? n : -n;
		while (ln > 0)
		{
			str[--size] = ln % 10 + '0';
			ln /= 10;
		}
	}
	return (str);
}
