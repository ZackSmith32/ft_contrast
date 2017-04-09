/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:32:58 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/15 19:02:25 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_struct(t_gnl *temp, char **line)
{
	int		i;
	char	*str;

	if (ft_strlen(temp->content) == 0)
		return (0);
	i = 0;
	while (temp->content[i] != '\n' && temp->content[i] != '\0')
		i++;
	free(*line);
	*line = (char *)ft_memalloc(i + 1);
	ft_strncpy(*line, temp->content, (size_t)i);
	if (temp->content[i] == 0)
	{
		ft_bzero(temp->content, i);
		return (0);
	}
	str = ft_strdup(temp->content + (i + 1));
	free(temp->content);
	temp->content = str;
	return (1);
}

static int		reading(int fd, char **line, char *buff)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while ((i = read(fd, buff, BUFF_SIZE)))
	{
		j = 0;
		if (i == -1)
			return (-1);
		buff[i] = '\0';
		while (buff[j] != '\n' && buff[j] != '\0')
			j++;
		temp = ft_strccat(*line, buff, '\n');
		free(*line);
		(*line) = temp;
		if (j != BUFF_SIZE)
			break ;
	}
	return (i);
}

static int		read_buf(int fd, t_gnl *item, char **line)
{
	char	*buff;
	char	*hld;
	int		i;
	int		j;

	j = 0;
	buff = (char *)ft_memalloc(BUFF_SIZE + 1);
	i = reading(fd, line, buff);
	hld = ft_strchr(buff, '\n');
	if (hld)
	{
		free(item->content);
		item->content = ft_strdup(hld + 1);
	}
	free(buff);
	if (i == -1)
		return (-1);
	if (i != BUFF_SIZE)
		return (0);
	return (1);
}

static int		central(t_gnl *temp, char **line, t_gnl **head)
{
	int		ret;

	if (check_struct(temp, line))
		return (1);
	ret = read_buf(temp->fd, temp, line);
	if (ret)
		return (ret);
	if (ft_strlen(*line) != 0)
		return (1);
	free_gnl(head, temp->fd);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*temp;

	if (fd < 0 || line == 0)
		return (-1);
	*line = (char *)ft_memalloc(1);
	if (head == NULL)
	{
		head = (t_gnl *)ft_memalloc(sizeof(t_gnl));
		head->fd = fd;
	}
	temp = head;
	while (temp->fd != fd)
	{
		if (temp->next == NULL)
		{
			temp->next = (t_gnl *)ft_memalloc(sizeof(t_gnl));
			temp = temp->next;
			temp->fd = fd;
			break ;
		}
		temp = temp->next;
	}
	return (central(temp, line, &head));
}
