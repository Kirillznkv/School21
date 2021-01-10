/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predparser_v0.3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:07:38 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/10 18:14:29 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

int			check_settings(int fd, int *settings[8])
{

}

int			predparser(char *filename, int *spases, int *w, int *h)
{
	int		fd;
	int		i;
	int		settings[8];

	i = -1;
	while (++i < 8)
		settings[i] = 0;
	fd = open(filename, O_RDONLY);
	if (check_settings(fd, &settings) != 1)
	{
		close(fd);
		return (-1);//return_error_code
	}
	if (check_map(fd, spases, w, h) != 1)
	{
		close(fd);
		return (-1);//return_error_code
	}
	close(fd);
	return (1);
}