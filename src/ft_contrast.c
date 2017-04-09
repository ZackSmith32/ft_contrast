/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 09:56:53 by zsmith            #+#    #+#             */
/*   Updated: 2017/04/09 15:11:21 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "../includes/contrast.h"

// int			read_set_header(char *line, struct t_contrast data)
// {
// 	data.max_val = ft_atoi(line);
// }

int			calc_out(char **split, struct t_contrast *data)
{
	int i;
	int j;
	int new_val;

	i = 0;
	while (split[i] != NULL)
	{
		new_val = (ft_atoi(split[i]) * data->contrast_level) / 100;
		ft_putnbr_fd(new_val, data->output_fd);
		ft_putstr_fd(" ", data->output_fd);
		printf("%d ", new_val);
		i++;
	}
	printf("\n");
	ft_putstr_fd("\n", data->output_fd);
	return (0);
}

int			ft_contrast(struct t_contrast *data)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(data->input_fd, &line) > 0)
	{
		printf("%s\n", line);
		if (i == 2)
		{
			printf("line: %s|\n", line);
			data->max_val = atoi(line);
			printf("data.max: %d\n", data->max_val);
		}
		else if (i > 2)
			calc_out(ft_strsplit(line, ' '), data);
		printf("\n");
		i++;
	}
	close(data->input_fd);
	close(data->output_fd);
	return (0);
}

int			main(int ac, char **av)
{
	int		input_fd;
	int		output_fd;
	struct	t_contrast data;
	
	if (ac != 7)
	{
		ft_puterror("bad input\n");
		return (0);
	}
	data.input_fd = open(av[2], O_RDONLY);
	data.output_fd = open(av[6], O_CREAT | O_RDWR, 0777);
	data.contrast_level = ft_atoi(av[4]);
	ft_contrast(&data);
	printf("data.max = %d\n", data.max_val);
	return (0);
}


/*
** gcc src/ft_contrast.c -I includes/contrast.h -L. libdir/libft/libft.a && ./a.out  -f feep2.pgm -c 12 -o out.pgm
*/