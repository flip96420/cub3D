/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 03:45:20 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/15 12:28:01 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Concatenates the strings 'dst' and 'src' 
/// and returns its coresponding length
/// including the NULL-terminator.
/// @param dst 
/// @param src 
/// @param size 
/// @return 
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	count_s;
	size_t			count_d;
	size_t			count_res;

	count_s = 0;
	count_d = ft_strlen(dst);
	count_res = ft_strlen(src);
	if (size < count_d)
		count_res += size;
	else
		count_res += count_d;
	while (src[count_s] != '\0' && (count_d + 1) < size)
	{
		dst[count_d] = src[count_s];
		count_s++;
		count_d++;
	}
	dst[count_d] = '\0';
	return (count_res);
}
