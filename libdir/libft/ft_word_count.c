/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 20:50:14 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/15 19:01:07 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int		ft_word_count(char const *s, char c)
{
	int		w;
	int		i;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			w++;
		else if (i == 0 && s[i] == c)
			;
		else if (
			(s[i - 1] == c && s[i] != c)
			&&
			(s[i] != '\0'))
			w++;
		i++;
	}
	return (w);
}
