/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:06:15 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/25 14:58:14 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Takes the string 'str', defines its startposition
/// 'start', as well as its endposition 'len' and returns
/// it as a new string.
/// @param str 
/// @param start 
/// @param len 
/// @return 
char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;
	size_t	str_size;

	str_size = ft_strlen(str) - (size_t)start;
	i = 0;
	if ((size_t)start >= ft_strlen(str))
		return (ft_strdup(""));
	if (str_size < len)
		ptr = malloc((str_size + 1) * sizeof (char));
	else
		ptr = malloc((len + 1) * sizeof (char));
	if (!ptr)
		return (NULL);
	while (str[start + i] && len > 0)
	{
		ptr[i] = str[start + i];
		len--;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
