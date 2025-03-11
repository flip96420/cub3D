/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:06:33 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/23 15:31:39 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Searches for a set of characters 'set'
/// in the string 'str' and returns a new string
/// where 'set' is trimmed, if found
/// at the beginning or the end of the string.
/// @param c 
/// @param set 
/// @return 
static int	check_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	unsigned int	i_start;
	unsigned int	i_end;

	if (!str)
		return (NULL);
	i_start = 0;
	i_end = ft_strlen(str) - 1;
	while (str[i_start])
		if (check_set(str[i_start], set))
			i_start++;
	else
		break ;
	if (i_start == ft_strlen(str))
		return (ft_strdup(""));
	while (str[i_end])
		if (check_set(str[i_end], set))
			i_end--;
	else
		break ;
	return (ft_substr(str, i_start, ((i_end + 1) - (size_t)i_start)));
}
