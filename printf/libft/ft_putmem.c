/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:26:08 by facolomb          #+#    #+#             */
/*   Updated: 2021/11/15 09:26:08 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len_mem(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	ft_print_mem(unsigned long num, char c)
{
	if (num >= 16)
	{
		ft_print_mem(num / 16, c);
		ft_print_mem(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (c == 'x')
				ft_putchar(num + 87);
			if (c == 'X')
				ft_putchar(num + 55);
		}
	}
}

int	ft_putmem(unsigned long num)
{
	int	size;

	size = 0;
	if (num == 0)
		size += ft_putstr("0x0");
	else
	{
		size += ft_putstr("0x");
		ft_print_mem(num, 'x');
		size += ft_len_mem(num);
	}
	return (size);
}
