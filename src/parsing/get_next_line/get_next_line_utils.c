/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:55:51 by tyi               #+#    #+#             */
/*   Updated: 2023/05/13 17:09:25 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ftt_len_or_chr(char *s, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		while (s[i])
			i ++;
		return (i);
	}
	else if (flag == 1)
	{
		while (s[i])
		{
			if ((unsigned char)s[i] == '\n')
				return (i);
			i ++;
		}
		return (-1);
	}
	else
		return (0);
}

char	*node_free(t_gnl_list **list, t_gnl_list *node, int flag)
{
	t_gnl_list	*tmp;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->next == node)
		{
			tmp->next = node->next;
			free (node->save);
			if (flag == 1)
			{
				free (node);
				if (!((*list)->next))
				{
					free (*list);
					(*list) = 0;
				}
			}
			return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_gnl_list	*init_node(int fd)
{
	t_gnl_list	*new;

	new = malloc(sizeof(t_gnl_list));
	if (fd != -1)
		new->save = ftt_calloc(1, 1);
	new->fd = fd;
	new->bytes = 0;
	new->next = 0;
	return (new);
}

t_gnl_list	*make_node(t_gnl_list **headp, int fd)
{
	t_gnl_list	*tmp;

	if (!*headp)
		*headp = init_node(-1);
	tmp = *headp;
	while ((tmp))
	{
		if (tmp->fd == fd)
		{
			ftt_bzero(tmp->buff, BUFFER_SIZE + 1);
			tmp->bytes = read(fd, tmp->buff, BUFFER_SIZE);
			if (tmp->bytes == -1)
				return ((void *)node_free(headp, tmp, 1));
			return (tmp);
		}
		if (!(tmp->next))
		{
			tmp->next = init_node(fd);
			if (!tmp->next)
				return (0);
			return (make_node(headp, fd));
		}
		tmp = tmp->next;
	}
	return (tmp);
}
