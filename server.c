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
#include "printf/ft_printf.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void	ft_sighandler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("salute");
	else
		ft_printf("auRevoir");
}

int	main(void)
{
	ft_printf("PID : %d", getpid());
	while(1)
	{
		signal(SIGUSR1, ft_sighandler);
		signal(SIGUSR2, ft_sighandler);
	}
}