/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:40:06 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/22 16:36:29 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Ignores all white spaces and 
/// converts an array into an integer.
/// '+' and '-' signs indicate whether the output 
/// should be a positive or a negative number.
/// @param str
/// @return
int	ft_atoi(const char *str)
{
	int	i;
	int	count_sign;
	int	res;

	res = 0;
	i = 0;
	count_sign = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while ((str[i] == '-' || str[i] == '+') && count_sign == 0)
	{
		count_sign = str[i];
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (count_sign == '-')
		res = -res;
	return (res);
}
