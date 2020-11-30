/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:37:19 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/30 17:12:17 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "./includes/ft_printf.h"

int			main()
{
	int		a = 0;
	int		b = 123;
	int		c = 12345678;

    a = ft_printf("|%14s|\n", "fbdsbfgjndhfnhdgndghnhgdn");
    b = printf("|%010.10x|\n", 123);

	ft_printf("ft_p = %d\np    = %d\n", a, b);

	return (0);
}
