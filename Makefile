# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 00:40:38 by macarval          #+#    #+#              #
#    Updated: 2022/11/25 21:13:24 by macarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minitalk
NAME_BONUS		= minitalk_bonus
SERVER			= server
SERVER_BONUS	= server_bonus
CLIENT			= client
CLIENT_BONUS	= client_bonus

FILE_PATH		= ./src
FILE_PATH_BONUS	= ./src_bonus
OBJS_PATH		= ./obj
LIBFT_PATH		= libft/
PRINTF_PATH		= ft_printf/

HEADERS			= minitalk.h
HEADERS_BONUS	= minitalk_bonus.h

LIBFT	= $(LIBFT_PATH)/libft.a
PRINTF	= $(PRINTF_PATH)/libftprintf.a

FILE_CLIENT			= client.c
FILE_CLIENT_BONUS	= client_bonus.c
FILE_SERVER			= server.c
FILE_SERVER_BONUS	= server_bonus.c

IFLAGS		= -I./libft -I./ft_printf
LFLAGS		= -L./libft -L./ft_printf -lftprintf -lft
CFLAGS		= -Wall -Wextra -Werror -O3

CC			= cc
RM			= rm -rf

OBJS_CLIENT			= $(addprefix $(OBJS_PATH)/, $(FILE_CLIENT:.c=.o))
OBJS_CLIENT_BONUS	= $(addprefix $(OBJS_PATH)/, $(FILE_CLIENT_BONUS:.c=.o))
OBJS_SERVER			= $(addprefix $(OBJS_PATH)/, $(FILE_SERVER:.c=.o))
OBJS_SERVER_BONUS	= $(addprefix $(OBJS_PATH)/, $(FILE_SERVER_BONUS:.c=.o))


all:		$(NAME)
$(NAME):	$(LIBFT) $(PRINTF) $(OBJS_PATH) $(SERVER) $(CLIENT)
			@echo "Minitalk created!!"

bonus:		$(NAME_BONUS)
$(NAME_BONUS):	$(LIBFT) $(PRINTF) $(OBJS_PATH) $(SERVER_BONUS) $(CLIENT_BONUS)
			@echo "Minitalk bonus created!!"

$(OBJS_PATH):
			@mkdir -p $(OBJS_PATH)

$(SERVER):	$(OBJS_SERVER)
			@$(CC) $(OBJS_SERVER) -o $(SERVER) $(LFLAGS)

$(SERVER_BONUS):	$(OBJS_SERVER_BONUS)
					@$(CC) $(OBJS_SERVER_BONUS) -o $(SERVER_BONUS) $(LFLAGS)

$(CLIENT):	$(OBJS_CLIENT)
			@$(CC) $(OBJS_CLIENT) -o $(CLIENT) $(LFLAGS)

$(CLIENT_BONUS):	$(OBJS_CLIENT_BONUS)
					@$(CC) $(OBJS_CLIENT_BONUS) -o $(CLIENT_BONUS) $(LFLAGS)

$(OBJS_PATH)/%.o: $(FILE_PATH)/%.c $(HEADERS)
			@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJS_PATH)/%.o: $(FILE_PATH_BONUS)/%.c $(HEADERS_BONUS)
			@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
			
$(PRINTF):
			@make -C $(PRINTF_PATH)

$(LIBFT):
			@make -C $(LIBFT_PATH)
			
			
clean:
			@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
			@echo "clean Done!"

fclean:		clean
			@make -C $(LIBFT_PATH) fclean
			@make -C $(PRINTF_PATH) fclean
			@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS) $(OBJS_PATH)
			@echo "fclean Done!"

re:			fclean all

.PHONY: 	all bonus clean fclean re