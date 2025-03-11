/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:46:44 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/14 17:33:27 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief ft_memmove behaves like ft_memcpy, while also
/// handling overlapping.
/// @param dst 
/// @param src 
/// @param len 
/// @return 
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	unsigned int		i;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	i = 0;
	if (dst_ptr < src_ptr)
	{
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else if (dst_ptr > src_ptr)
	{
		while (len > 0)
		{
			dst_ptr[len - 1] = src_ptr[len - 1];
			len--;
		}
	}
	return (dst);
}
