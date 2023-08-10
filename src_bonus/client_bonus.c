/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:53:20 by macarval          #+#    #+#             */
/*   Updated: 2022/11/25 21:31:11 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../minitalk_bonus.h"

int	g_confirm;

static void	receved_message(int num)
{
	if (num == SIGUSR1)
		g_confirm = 1;
}

static void	process_message(t_text info_client)
{
	unsigned char	bit;
	int				i;

	i = 0;
	while (info_client.text[i])
	{
		bit = 128;
		while (bit > 0)
		{
			if (!(info_client.text[i] & bit))
				kill(info_client.pid_server, SIGUSR1);
			else
				kill(info_client.pid_server, SIGUSR2);
			bit /= 2;
			while (!g_confirm)
				ft_printf("");
			g_confirm = 0;
		}	
		i++;
	}
}

int	main(int argc, char *argv[])
{	
	t_text	info_client;

	if (argc < 3)
		ft_printf("Invalid number of arguments!!\n");
	else
	{
		info_client.text = argv[2];
		info_client.pid_server = ft_atoi(argv[1]);
		g_confirm = 0;
		if (signal(SIGUSR1, &receved_message) == SIG_ERR)
		{
			ft_printf("Fatal error: SIGUSR1 setting failed\n");
			exit(EXIT_FAILURE);
		}
		process_message(info_client);
	}
}
