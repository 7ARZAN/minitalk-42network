/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:25:03 by elakhfif          #+#    #+#             */
/*   Updated: 2022/11/28 07:58:12 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_character(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSER2);
		else
			kill(pid, SIGUSER1);
		i--;
		usleep(500);
	}
}

void	handler(int sig)
{
	if (sig == SIGUSER1)
		ft_putstr("wslat bslamtha am3alem\n");
}

int	check_error(char *str)
{
	int	pid;
	int	i;

	pid = ft_atoi(str);
	if (pid < 0)
		return (0);
	i = kill(pid, 0);
	if (i == -1)
		return (0);
	return (pid);
}

int	main(int ac, char **av)
{
	char	*str;
	int		i;
	int		pid;

	i = 0;
	if (ac == 3)
	{
		pid = check_error(av[1]);
		if (pid > 0)
		{
			str = av[2];
			signal(SIGUSER1, handler);
			while (str[i])
			{
				send_character(pid, str[i]);
				i++;
			}
			send_character(pid, 0);
		}
		else
			ft_putstr("incorrect pid!\n");
	}
	else
		ft_putstr("Syntax Error!\n");
	return (0);
