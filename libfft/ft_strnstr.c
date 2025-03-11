/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:55:52 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/26 13:44:33 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Searches for the needle 'ndl' in the
/// haystack 'hstck'. If a needle is not found,
/// the 'hstck' gets returned. If a needle is found,
/// 'hstck' gets returned, starting at the position
/// from the first ocurence of 'ndl'.
/// @param hstck 
/// @param ndl 
/// @param len 
/// @return 
char	*ft_strnstr(const char *hstck, const char *ndl, size_t len)
{
	size_t	i_hstck;
	size_t	i_hstck_temp;
	int		i_ndl;
	int		ptr_pos;

	i_hstck_temp = 0;
	i_ndl = 0;
	if (!*ndl)
		return ((char *)hstck);
	while (hstck[i_hstck_temp] && i_ndl == 0)
	{
		i_hstck = i_hstck_temp;
		while (hstck[i_hstck] == ndl[i_ndl] && len > i_hstck)
		{
			ptr_pos = i_hstck;
			if (ndl[i_ndl + 1] == '\0')
				return ((char *)(hstck + (ptr_pos - i_ndl)));
			i_ndl++;
			i_hstck++;
		}
		i_ndl = 0;
		i_hstck_temp++;
	}
	return (NULL);
}
