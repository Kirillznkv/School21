/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:30:59 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/30 18:28:09 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

size_t			ft_strlen(const char *str)
{
	size_t		res;

	res = 0;
	if (str == NULL)
		return (0);
	while (str[res] != '\0')
		res++;
	return (res);
}
