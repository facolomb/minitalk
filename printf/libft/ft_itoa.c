/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:02:50 by facolomb          #+#    #+#             */
/*   Updated: 2021/10/27 09:39:38 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_nb_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_convert_i_to_c(char *str, int n, int len)
{
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

int	ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_nb_len(n);
	if (n == -2147483647 - 1)
		return (ft_putstr("-2147483648"));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (ft_putchar('\0'));
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	str[len--] = '\0';
	if (n == 0)
	{
		free(str);
		return (ft_putchar('0'));
	}
	str = ft_convert_i_to_c(str, n, len);
	len = ft_putstr(str);
	free(str);
	return (len);
}
