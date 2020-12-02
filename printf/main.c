/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:37:19 by kshanti           #+#    #+#             */
/*   Updated: 2020/12/02 17:08:52 by kshanti          ###   ########.fr       */
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

    a = ft_printf("sadnkj%dksdhfhk%d\n", 5, 5);
    b = printf("%5p\n", NULL);

	printf("ft_p = %d\np    = %d\n\n", a, b);
	while (1)
		;
	return (0);
}
