/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:20:05 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/02 20:14:15 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr_fd(int n, int fd)
{
	unsigned ln;

	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		if (n >= 0 && n <= 9)
			ft_putchar_fd(n + '0', fd);
		else
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-(n / 10), fd);
			ln = -n;
			ft_putchar_fd(ln % 10 + '0', fd);
		}
	}
}
