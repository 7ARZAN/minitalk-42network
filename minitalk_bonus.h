/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:26:01 by elakhfif          #+#    #+#             */
/*   Updated: 2022/11/25 06:26:03 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>

void  ft_putstr(char *str);
int   ft_atoi(const char *str);
void  ft_putnbr(int n);
void  ft_putchar(char c);

#endif
