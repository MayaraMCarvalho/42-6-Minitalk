/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:21:17 by macarval          #+#    #+#             */
/*   Updated: 2022/11/10 04:06:05 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h> 

typedef struct s_text
{
	const char			*text;
	struct sigaction	control;
	int					massage;
	int					pid_server;
	int					pid_client;
	int					count_char;
}	t_text;

#endif