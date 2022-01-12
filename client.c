/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:37:04 by facolomb          #+#    #+#             */
/*   Updated: 2022/01/10 13:37:04 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		kill(pid, SIGUSR1);
	}
}