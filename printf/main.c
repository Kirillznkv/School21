/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:37:19 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/22 19:07:22 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
//#include "/includes/ft_printf.h"

int			main()
{
	int		a = 5;
	int		b = 123;
	int		c = 12345678;
	printf("5: (- -)\t|%d|\n", a);
	printf("5: (8 -)\t|%8d|\n", a);
	printf("5: (- 8)\t|%.8d|\n", a);
	printf("5: (4 8)\t|%4.8d|\n", a);

	printf("\n");
	printf("5: (4 2)\t|%4.2d|\n", a);

	printf("\n");
	printf("5:\t|%5.1d|\n", c);
	printf("5:\t|%10.1s|\n", "sfkjhfjk");
	return (0);
}
