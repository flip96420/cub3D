/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:35:36 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/25 14:53:15 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief compares 'n' times characters from 'str1' and 'str2'
/// and returns their difference
/// @param str1 
/// @param str2 
/// @param n 
/// @return 
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((str1[i] == str2[i]) && i < (n - 1) && (str1[i] && str2[i]))
		i++;
	return ((int)(unsigned char)str1[i] - (unsigned char)str2[i]);
}
