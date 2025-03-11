/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:41:21 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/25 14:49:37 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates 'count * size' memory and 
/// writes the corresponding amount 
/// of zeroed bytes to a void pointer.
/// @param count
/// @param size
/// @return 
void	*ft_calloc(unsigned int count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size) / sizeof(char));
	return (ptr);
}
