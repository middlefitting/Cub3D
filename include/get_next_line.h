/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:17:48 by tyi               #+#    #+#             */
/*   Updated: 2023/05/13 17:11:56 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 32

typedef struct s_gnl_list
{
	char				buff[BUFFER_SIZE + 1];
	char				*save;
	int					fd;
	int					bytes;
	struct s_gnl_list	*next;
}						t_gnl_list;

char		*get_next_line(int fd);
int			ftt_len_or_chr(char *s, int flag);
void		ftt_bzero(void *s, size_t n);
void		*ftt_calloc(size_t count, size_t size);
char		*node_free(t_gnl_list **list, t_gnl_list *node, int flag);
t_gnl_list	*init_node(int fd);
char		*ftt_strjoin(char *s1, char *s2);
t_gnl_list	*make_node(t_gnl_list **headp, int fd);
char		*ftt_substr(char **save, int s_i);
char		**ftt_split(char const *s, char c);
#endif
