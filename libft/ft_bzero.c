/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:40:48 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/25 14:49:31 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Wirtes 'len' times zeroed bytes 
/// to the void string 'str' using (char *)typecasting. 
/// @param str 
/// @param len 
void	ft_bzero(void *str, size_t len)
{
	char	*d;

	d = (char *)str;
	while (len--)
		*d++ = 0;
}
