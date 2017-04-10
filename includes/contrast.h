/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contrast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 12:29:21 by gselbo            #+#    #+#             */
/*   Updated: 2017/04/09 23:09:33 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTRAST_H
# define CONTRAST_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#include "libft.h"

#define NUM_THREADS	100
#define	BUFF_SIZE_T 100000

struct 		t_contrast
{
	int		input_fd;
	int		output_fd;
	int		max_val;
	int		contrast_level;	
};

char	*g_chunks[NUM_THREADS];
int		g_contrast_level;
#endif