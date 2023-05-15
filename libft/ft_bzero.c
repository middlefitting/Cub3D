/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:18:15 by sechung           #+#    #+#             */
/*   Updated: 2023/05/15 15:18:56 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t size)
{
	size_t			i;
	unsigned char	*c_dest;

	i = 0;
	c_dest = (unsigned char *) dest;
	while (i < size)
	{
		c_dest[i] = 0;
		i++;
	}
}
