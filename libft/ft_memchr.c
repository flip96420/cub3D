/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:45:04 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/22 14:50:28 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Locates the first occurence of 'c' in 'str' 
/// within the range of 'n' and returns a pointer to that location.
/// The pointer gets typecasted into an 
///'unsinged char *' before it gets returned.
/// @param str 
/// @param c 
/// @param n 
/// @return 
void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*str_ptr;
	size_t		i;

	str_ptr = str;
	i = 0;
	while (i < n)
	{
		if (str_ptr[i] == (char)c)
			return ((void *)(str_ptr + i));
		i++;
	}
	return (0);
}
