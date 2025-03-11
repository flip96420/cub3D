/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:36:14 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/19 18:19:45 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Takes the character 'c' 
/// and writes it 'len' times
/// to the string 'str' and returns a pointer
/// with typecasting of 'unsigned char *'.
/// @param str 
/// @param c 
/// @param len 
/// @return 
void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*str_ptr;

	str_ptr = (unsigned char *)str;
	while (len > 0)
	{
		*str_ptr++ = (unsigned char)c;
		len--;
	}
	return (str);
}
