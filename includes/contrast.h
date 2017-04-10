/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contrast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 12:29:21 by gselbo            #+#    #+#             */
/*   Updated: 2017/04/09 12:51:14 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTRAST_H
# define CONTRAST_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

struct 		t_contrast
{
	int		input_fd;
	int		output_fd;
	int		max_val;
	int		contrast_level;	
};

#endif