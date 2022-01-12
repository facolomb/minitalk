/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:14:41 by facolomb          #+#    #+#             */
/*   Updated: 2021/10/27 09:42:04 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	is_found;
	int	nb_word;

	is_found = 0;
	nb_word = 0;
	while (*s != '\0')
	{
		if (*s != c && is_found == 0)
		{
			nb_word++;
			is_found = 1;
		}
		else if (*s == c)
			is_found = 0;
		s++;
	}
	return (nb_word);
}

static char	*ft_stock_word(const char *s, int start, int end)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_stock_in_str(const char *s, char c, char **str)
{
	int		start;
	size_t	i;
	int		y;

	start = -1;
	i = 0;
	y = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			str[y++] = ft_stock_word(s, start, i);
			start = -1;
		}
		i++;
	}
	str[y] = 0;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = ft_stock_in_str(s, c, str);
	return (str);
}
