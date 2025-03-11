/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:40:33 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/15 19:17:58 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies 'len' characters from the srtring 'src'
/// to the string 'dst'. The output gets
/// typecasted into an 'unsigned char *'
/// before it gets returned.
/// @param dst 
/// @param src 
/// @param len 
/// @return 
void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (!dst && !src)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	while (len > 0)
	{
		*dst_ptr++ = *src_ptr++;
		len--;
	}
	return (dst);
}
