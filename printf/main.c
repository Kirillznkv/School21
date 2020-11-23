/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:37:19 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/23 19:29:50 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "./includes/ft_printf.h"

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
	printf("5:\t|%6.1d|\n", -12);

	/*a = ft_printf("sjakfhkf45435\naabb     "
               "|%d|     aabb     "
               "|%0d|    \nslflfjd    "
               "|%.7d|    kffkldv\n    "
               "|%4.d|    ,     "
               "|%04.5d|   \n   "
               "|%-20.89d|   \n", b, c, -378, 7, 7, -a);*/
	return (0);
}
