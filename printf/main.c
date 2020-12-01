/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:37:19 by kshanti           #+#    #+#             */
/*   Updated: 2020/12/01 19:23:33 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "./includes/ft_printf.h"

int			main()
{
	int		a = 0;
	int		b = 123;
	int		c = 12345678;
	char *d = "asdfg";

    a = ft_printf("%5p\n", NULL);
    b = printf("%5p\n", NULL);

	printf("ft_p = %d\np    = %d\n\n", a, b);


    //a = ft_printf("|%.p|\n", NULL);
    //b = printf("|%.p|\n", NULL);

	//printf("ft_p = %d\np    = %d\n", a, b);
	return (0);
}
