/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:21:46 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/23 15:18:32 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*allocate(int len)
{
	char	*ptr;

	ptr = malloc((len + 1) * sizeof (char));
	if (!ptr)
		return (NULL);
	else
		return (ptr);
}

char	*convert(int nbr, int nbr_temp, int len, int count_sign)
{
	char	*ptr;
	int		i;

	while (nbr_temp > 0)
	{
		nbr_temp = nbr_temp / 10;
		len++;
	}
	ptr = allocate(len);
	if (!ptr)
		return (NULL);
	i = len;
	while (nbr > 0)
	{
		i--;
		ptr[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (count_sign == 1)
		ptr[0] = '-';
	ptr[len] = '\0';
	return (ptr);
}

/// @brief Converts an integer into an array.
/// Also adds the '-'sign in front of the string, 
/// in case the integer is a negative number.
/// @param nbr
/// @return 
char	*ft_itoa(int nbr)
{
	int		len;
	int		nbr_temp;
	int		count_sign;

	len = 0;
	count_sign = 0;
	nbr_temp = nbr;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (nbr == 0)
		return (ft_strdup("0"));
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			nbr_temp = -nbr_temp;
			len = 1;
			count_sign = 1;
		}
		return (convert(nbr, nbr_temp, len, count_sign));
	}
}
