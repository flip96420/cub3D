/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:10:10 by pschmunk          #+#    #+#             */
/*   Updated: 2023/06/23 15:19:31 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *str, char c)
{
	unsigned int	i;
	int				word_count;
	unsigned int	sep_nbr;

	i = 0;
	word_count = 0;
	sep_nbr = 0;
	while (str[i])
	{
		if (str[i] == c)
			sep_nbr++;
		if (str[i] != c && str[i + 1] == c)
			word_count++;
		i++;
	}
	if (str[i - 1] == c)
		word_count--;
	if (sep_nbr == ft_strlen(str))
		word_count = -1;
	return (word_count);
}

char	*create_word(const char *str, int word_start, int word_end, char c)
{
	int		word_len;
	char	*ptr;

	word_len = word_end - word_start;
	ptr = malloc((word_len + 2) * sizeof (char));
	if (!ptr)
		return (NULL);
	ptr[word_len + 1] = '\0';
	while (word_len >= 0 && str[word_end] != c)
	{
		ptr[word_len] = str[word_end];
		word_len--;
		word_end--;
	}
	return (ptr);
}

char	*find_word(const char *str, unsigned int i_word, char c)
{
	int				i;
	unsigned int	word_count;
	int				word_start;
	int				word_end;

	i = 0;
	word_start = 0;
	word_count = 0;
	word_end = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			word_count++;
			if (word_count == (i_word + 1))
			{
				word_end = i;
				break ;
			}
		}
		else if (str[i + 1] != c && str[i] == c)
			word_start = i + 1;
		i++;
	}
	return (create_word(str, word_start, word_end, c));
}

char	**edgecase(const char *str, int check_case)
{
	char	**ptr;

	if (check_case == 0)
	{
		ptr = malloc(1 * sizeof (char *));
		ptr[0] = NULL;
		return (ptr);
	}
	ptr = malloc(2 * sizeof (char *));
	ptr[0] = ft_strdup(str);
	ptr[1] = NULL;
	return (ptr);
}

/// @brief Splits the string 'str' into multiple strings using 'c'
/// as a seperator and stores them into an 2D array.
///	The right amount of memory gets allocated for each string
/// + the 2D array, before it gets returned.
/// @param str 
/// @param c 
/// @return 
char	**ft_split(const char *str, char c)
{
	int		i;
	int		nbr_words;
	char	**ptr;

	if (!*str)
		return (ft_calloc(1, sizeof(char *)));
	if (!c)
		return (edgecase(str, 1));
	i = 0;
	nbr_words = count_words(str, c);
	if (nbr_words == -1)
		return (edgecase(str, 0));
	ptr = malloc((nbr_words + 2) * sizeof (char *));
	if (!ptr)
		return (NULL);
	while (i <= nbr_words)
	{
		ptr[i] = find_word(str, i, c);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
