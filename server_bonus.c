/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:25:14 by elakhfif          #+#    #+#             */
/*   Updated: 2022/11/28 08:15:20 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_pid = 0;

void	handler(int signum, siginfo_t *sig_info, void *context)
{
	static char	ascii;
	static int	i;

	(void) context;
	signum -= SIGUSER1;
	if (g_pid != sig_info->si_pid)
	{
		ascii = 0;
		i = 0;
		g_pid = sig_info->si_pid;
	}
	if (signum)
		ascii = ascii << 1 | 1;
	if (!signum)
		ascii = ascii << 1 | 0;
	i++;
	if (i == 8)
	{
		if (ascii == '\0')
			kill(g_pid, SIGUSER1);
		ft_putchar(ascii);
		i = 0;
		ascii = 0;
	}
}

int	main(void)
{
	struct sigaction	g;

	g.sa_sigaction = &handler;
	g.sa_flags = SA_SIGIMFO;
	sigaction(SIGUSER1, &g, NULL);
	sigaction(SIGUSER2, &g, NULL);
	ft_putstr("PID = ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (1)
		pause();
