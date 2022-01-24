/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:37:13 by facolomb          #+#    #+#             */
/*   Updated: 2022/01/10 13:37:13 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	ft_bintodec(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '1')
		i += 1;
	if (str[1] == '1')
		i += 2;
	if (str[2] == '1')
		i += 4;
	if (str[3] == '1')
		i += 8;
	if (str[4] == '1')
		i += 16;
	if (str[5] == '1')
		i += 32;
	if (str[6] == '1')
		i += 64;
	return (i);
}

void	ft_managebin(char *bin)
{
	static char	*str;
	char		*tmp;
	int			c;

	if (!str)
		str = ft_strdup(bin);
	else
	{
		tmp = str;
		str = ft_strjoin(str, bin);
		free(tmp);
	}
	c = ft_strlen(str);
	if (c == 7)
	{
		c = ft_bintodec(str);
		ft_putchar(c);
		free(str);
		str = NULL;
	}
}

void	ft_sighandler(int signum)
{
	if (signum == SIGUSR1)
		ft_managebin("1");
	else
		ft_managebin("0");
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR1, ft_sighandler);
	signal(SIGUSR2, ft_sighandler);
	while (1)
	{
		pause();
	}
}
