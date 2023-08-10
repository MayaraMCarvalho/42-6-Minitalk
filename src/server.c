/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:39:14 by macarval          #+#    #+#             */
/*   Updated: 2022/11/24 23:04:26 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../minitalk.h"

t_text	g_info_server;

static void	translate_message(int binary)
{
	if (g_info_server.count_char-- > 0)
	{
		g_info_server.massage |= (binary << g_info_server.count_char);
		if (g_info_server.count_char == 0)
		{
			ft_printf("%c", g_info_server.massage);
			g_info_server.count_char = 8;
			g_info_server.massage = 0;
		}	
	}
	kill(g_info_server.pid_client, SIGUSR1);
}

static void	print_message(int sig, siginfo_t *info, void *secret)
{
	(void)secret;
	g_info_server.pid_client = info->si_pid;
	if (sig == SIGUSR1)
		translate_message(0);
	if (sig == SIGUSR2)
		translate_message(1);
}

int	main(void)
{		
	g_info_server.massage = 0;
	g_info_server.count_char = 8;
	g_info_server.control.sa_flags = SA_SIGINFO;
	g_info_server.control.sa_sigaction = &print_message;
	ft_printf("\nServer's PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &g_info_server.control, NULL) < 0)
	{
		ft_printf("Fatal error: SIGUSR1 setting failed\n");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &g_info_server.control, NULL) < 0)
	{
		ft_printf("Fatal error: SIGUSR2 setting failed\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
