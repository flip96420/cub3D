/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:30:06 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/14 17:45:47 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Writes the character 'c'
/// using the write function.
/// 'fd' sets the file descriptor.
/// @param c 
/// @param fd 
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
