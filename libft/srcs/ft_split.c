/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:56:58 by eviala            #+#    #+#             */
/*   Updated: 2024/07/22 10:56:33 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

// Function to create a word from start to end indices
static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)ft_calloc((end - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i++] = str[start++];
	}
	word[i] = '\0';
	return (word);
}

// Count number of words in the string
static int	word_count(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

// Split function
char	**ft_split(const char *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	size_t (i) = 0;
	int (j) = 0;
	int (s_word) = -1;
	res = (char **)ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			res[j] = fill_word(s, s_word, i);
			if (!res[j])
				return (ft_free(res, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	return (res);
}
