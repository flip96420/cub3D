/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 03:08:09 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/15 17:57:10 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*cpy;
	unsigned int	count;

	count = 0;
	cpy = malloc((ft_strlen(str) + 1) * sizeof (char));
	if (!cpy)
		return (NULL);
	while (str[count] != '\0')
	{
		cpy[count] = str[count];
		count++;
	}
	cpy[count] = '\0';
	return (cpy);
}
