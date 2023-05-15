/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:10:47 by tyi               #+#    #+#             */
/*   Updated: 2023/05/15 16:14:50 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "cub3d.h"

void	parsing(t_info *info, char *path);
void	check_map_valid(t_info *info);
void	step1(t_info *info, int fd);
void	step2(t_info *info, int fd);
void	exit_with_error(char *msg);
int		ftt_strlen(char *str);
int		ftt_strcmp(char *s1, char *s2);
int		ftt_atoi(char *str);
int		line_is_new_line(char *line);
int		line_is_in_map(t_info *info);
void	print_info(t_info *info);
void	check_file_open(char **path, char *value);
int		cub_file_open(char *path);
int		ftt_double_arr_len(char **arr);
void	free_double_arr(char **arr);

#endif
