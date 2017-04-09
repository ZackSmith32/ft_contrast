/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 09:56:53 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/09 11:36:24 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int			ft_contrast(char *in_file, unsigned int contrast, int out_file)
{

}


int			main(int ac, char **av)
{
	if (ac != 7)
	{
		ft_puterror("bad input\n");
		return (0);
	}
	ft_contrast(av[2], ft_atoi(av[5]), )
	return (0);
}

