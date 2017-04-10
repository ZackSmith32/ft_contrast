/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 09:56:53 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/09 23:30:15 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/contrast.h"

void			*calc_out(void *arg)
{
	int 			i;
	int				j;
	unsigned short	new_val;
	char			**split;
	int				thread_number;
	char			*str;

	i = 0;
	thread_number = (int)arg;
	printf("in thread : %d\n", thread_number);
	str = g_chunks[thread_number];
	while (i < BUFF_SIZE_T)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			new_val = (unsigned short)((ft_atoi(&str[i]) * g_contrast_level) / 100);

			i++;
			if (str[i] == ' ')
				i++;
		}
		else
			i++;

		// ft_putnbr_fd(new_val, file_data->output_fd);
		// ft_putstr_fd(" ", file_data->output_fd);
	}
	// ft_putstr_fd("\n", file_data->output_fd);
	return (NULL);
}

int			ft_contrast(struct t_contrast *file_data)
{
	char	*line;
	int		proc_count;
	long		i;
	int		rc;
	int		ret;
	pthread_t thread[NUM_THREADS];
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	i = 0;
	while ((ret = read(file_data->input_fd, g_chunks[i], BUFF_SIZE_T)))
	{
		g_chunks[i][BUFF_SIZE_T] = '\0';
		printf("ft_contrast: creating thread %ld, ret = %d, fd = %d\n", i, ret, file_data->input_fd);
		rc = pthread_create(&thread[i], &attr, &calc_out, (void *)i);
		if (rc) 
		{
			printf("ERROR: return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
		i++;
	}
	pthread_exit(NULL);
	return (0);
}


int			main(int ac, char **av)
{
	struct	t_contrast file_data;
	int		i;

	if (ac != 7)
	{
		ft_puterror("bad input\n");
		return (0);
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		g_chunks[i] = (char *)ft_memalloc(BUFF_SIZE_T);
		i++;
	}
	printf("input_fd = %s\n", av[2]);
	file_data.input_fd = open(av[2], O_RDONLY);
	file_data.output_fd = open(av[6], O_CREAT | O_RDWR, 0777);
	g_contrast_level = ft_atoi(av[4]);
	ft_contrast(&file_data);
	close(file_data.input_fd);
	close(file_data.output_fd);
	return (0);
}


/*
** gcc src/ft_contrast.c -I includes/contrast.h -L. libdir/libft/libft.a && ./a.out  -f feep2.pgm -c 12 -o out.pgm
*/