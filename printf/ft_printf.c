/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:09:15 by facolomb          #+#    #+#             */
/*   Updated: 2021/11/09 12:35:16 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	ft_manage_flags(const char *str, va_list *params, int i)
{
	int	size;

	size = 0;
	if (str[i] == 'c')
		size += ft_putchar((int) va_arg(*params, int));
	else if (str[i] == '%')
		size += ft_putchar('%');
	else if (str[i] == 's')
		size += ft_putstr((char *) va_arg(*params, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		size += ft_itoa((int) va_arg(*params, int));
	else if (str[i] == 'u')
		size += ft_uitoa((unsigned int) va_arg(*params, unsigned int));
	else if (str[i] == 'p')
		size += ft_putmem((unsigned long) va_arg(*params, unsigned long));
	else if (str[i] == 'x')
		size += ft_itohex((unsigned int) va_arg(*params, unsigned int), 'x');
	else if (str[i] == 'X')
		size += ft_itohex((unsigned int) va_arg(*params, unsigned int), 'X');
	return (size);
}

int	ft_printf(const char *s, ...)
{
	char	*str;
	int		i;
	int		count;
	va_list	params;

	i = 0;
	count = 0;
	str = (char *)s;
	va_start(params, s);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count += ft_manage_flags(str, &params, ++i);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(params);
	return (count);
}
