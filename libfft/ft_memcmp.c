/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:45:42 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/25 14:51:14 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Returns an integer, which represents
/// the difference of 'str1' and 'str2'.
/// Output gets typecasted into an
/// 'const unsigned char *' before it gets returned.
/// @param str1 
/// @param str2 
/// @param n 
/// @return 
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;
	size_t				i;

	s1_ptr = (const unsigned char *) str1;
	s2_ptr = (const unsigned char *) str2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1_ptr[i] == s2_ptr[i] && i < (n - 1))
		i++;
	return (s1_ptr[i] - s2_ptr[i]);
}
