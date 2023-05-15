/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:26:30 by tyi               #+#    #+#             */
/*   Updated: 2023/05/15 15:18:12 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "parsing.h"

void	check_argv_invalid(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 1)
		exit_with_error("no map file error");
	else if (ac != 2)
		exit_with_error("too many arguments error");
	else
	{
		while (av[1][i])
			i++;
		if (i < 5)
			exit_with_error("invalid map file error");
		if (ft_strcmp(av[1] + i - 4, ".cub") != 0)
			exit_with_error("invalid cub file error");
	}

}

int	main(int ac, char **av)
{
	t_info	info;

	check_argv_invalid(ac, av);
	parsing(&info, av[1]);
	executer(&info);
	return (0);
}
