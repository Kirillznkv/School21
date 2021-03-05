/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:32:22 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 12:47:28 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void					fsm1(int *end, int *h)
{
	(*end)++;
	(*h)++;
}

void					fsm2(int *end, int *h, int *w, char **line)
{
	*end = 0;
	checkline_map(*line, w, h);
}

void					fsm3(int *end, int *flag)
{
	*flag = 0;
	*end = 0;
}

void					fsm4(int *check_gnl)
{
	if (*check_gnl == -1)
		error_system(errno);
}
