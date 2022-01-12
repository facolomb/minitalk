/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 09:03:19 by facolomb          #+#    #+#             */
/*   Updated: 2021/10/27 09:45:36 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			str_len;
	unsigned int	i;

	if (!s)
		return (NULL);
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	str_len = 0;
	if (str == NULL)
		return (NULL);
	while (i < start)
	{
		i++;
	}
	while (str_len < len && start < ft_strlen(s))
	{
		str[str_len] = s[i];
		str_len++;
		i++;
	}
	str[str_len] = '\0';
	return (str);
}
