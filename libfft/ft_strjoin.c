/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:56:19 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/25 14:52:40 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates the memory for the concatenation
/// of 'str1' and 'str2' and then returns the
/// concatenated string.
/// @param str1 
/// @param str2 
/// @return 
char	*ft_strjoin(const char *str1, const char *str2)
{
	unsigned int	count_1;
	unsigned int	count_2;
	char			*ptr;

	count_1 = 0;
	count_2 = 0;
	ptr = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof (char));
	if (!ptr)
		return (NULL);
	while (str1[count_1])
	{
		ptr[count_1] = str1[count_1];
		count_1++;
	}
	while (str2[count_2])
	{
		ptr[count_1] = str2[count_2];
		count_1++;
		count_2++;
	}
	ptr[count_1] = '\0';
	return (ptr);
}
