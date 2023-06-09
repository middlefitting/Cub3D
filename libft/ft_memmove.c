/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:29:51 by sechung           #+#    #+#             */
/*   Updated: 2023/04/12 22:37:57 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*c_dest;
	char	*c_src;

	c_dest = (char *) dest;
	c_src = (char *) src;
	i = 0;
	if (dest < src)
	{
		while (i < size)
		{
			*c_dest++ = *c_src++;
			i++;
		}
	}
	else if (dest > src)
	{
		c_dest += size;
		c_src += size;
		while (size--)
			*--c_dest = *--c_src;
	}
	return (dest);
}
