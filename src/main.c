/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:26:30 by tyi               #+#    #+#             */
/*   Updated: 2023/05/13 15:28:24 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	parsing(t_info *info, char *path);

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		exit(1);
	parsing(&info, av[1]);
	executer(&info);
	return (0);
}
