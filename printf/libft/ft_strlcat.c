/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 09:51:32 by facolomb          #+#    #+#             */
/*   Updated: 2021/10/27 09:43:23 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	n;
	int		i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	n = 0;
	i = 0;
	if (size > 0)
	{
		while (dst[n] != '\0')
			n++;
		while (n < size - 1)
		{
			dst[n] = src[i];
			n++;
			i++;
		}
		dst[n] = '\0';
	}
	if (size < len_dst)
		return (len_src + size);
	return ((len_dst + len_src));
}
