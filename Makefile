# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 04:35:56 by elakhfif          #+#    #+#              #
#    Updated: 2022/11/28 07:37:34 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = minitalk.h
INC_BONUS = minitalk_bonus.h

CFLAGS = -Wall -Wextra -Werror


all : server client

bonus: server_bonus client_bonus

server: server.c minitalk_utils.c $(INC)
	cc $(CFLAGS) server.c minitalk_utils.c -o server

client: client.c minitalk_utils.c $(INC)
	cc $(CFLAGS) client.c minitalk_utils.c -o client
	
server_bonus: server_bonus.c minitalk_utils.c $(INC_BONUS)
	cc $(CFLAGS) server_bonus.c minitalk_utils.c -o server_bonus

client_bonus: client_bonus.c minitalk_utils.c $(INC_BONUS)
	cc $(CFLAGS)  client_bonus.c minitalk_utils.c -o client_bonus

clean:
	
fclean : clean
	rm -rf server server_bonus client client_bonus

re : fclean all
