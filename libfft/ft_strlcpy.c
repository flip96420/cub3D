/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:05:54 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/25 14:52:54 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies 'size - 1' times characters from 'src'
/// to the 'dst' string and returns its length
/// including the NULL-Terminator.
/// @param dst 
/// @param src 
/// @param size 
/// @return 
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (i < (size - 1) && size != 0)
		{
			dst[i] = src[i];
			j++;
		}
		i++;
	}
	if (size != 0)
		dst[j] = '\0';
	return (i);
}
