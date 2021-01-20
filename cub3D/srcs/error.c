/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:14:07 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/20 12:58:04 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void			error_control(char *str)
{
	ft_putstr_fd("error: ", 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	exit(-1);
}

void			error_system(int error)
{
	if (error)
	{
		perror("error");
		exit(error);
	}
}