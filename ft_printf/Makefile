# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 00:40:38 by macarval          #+#    #+#              #
#    Updated: 2022/11/04 01:09:56 by macarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES		= ft_printf_control.c ft_printf_utils.c \
			ft_printf.c 
# Declare all files that will be used.

FIL_BON		= ft_format_bonus.c ft_printf_control_bonus.c \
			ft_printf_utils_bonus.c ft_printf_bonus.c 
			
# Declare all files that will be used.

EXE		= $(FILES:.c=.o)
# Create list of executable filenames.
# Replacing the .c extension with .o

EXE_BON	= $(FIL_BON:.c=.o)
# Create list of executable filenames.
# Replacing the .c extension with .o

NAME		= libftprintf.a
# Declare library name to be generated.

AR			= ar -crs
# Declare command ar.
# Creates the repository (even if it already exists).
# Replace or add file to repository (r).

GCC			= cc
# Declares the compiler nome that will be
# used in the build process.

CFLAGS		= -Wall -Wextra -Werror
# Declares the flags that will be used by the compiler.

all:		$(NAME)
# Run libft.a (see above)

$(NAME):	$(EXE)
			@$(AR) $(NAME) $(EXE)
			@echo "Printf created!!"
#$(LIB) $(NAME)
# $(NAME): File name (library) that the program will generate.
# $(EXE) : File that will be used as input when creating the library.
# Remainder: Actions that make will perform.

.c.o:
			@$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus:		$(EXE_BON)
			$(AR) $(NAME) $(EXE_BON)
# Run bonus
		
# Declare rule.
# gcc -Wall -Wextra -Werror -c ...
# -c: compiles and converts to machine language without linking
# (does not create the executable program).
# -o file: output file name (.out).
# $<: stores the rule's first prerequisite's name.
# <:.c=.o: modify the name extension of the rule's first prerequisite
# to make .o

clean:
			@rm -f $(EXE) $(EXE_BON) $(NAME_BON)
			@echo "clean Done!"
# Remove all executables without confirmation.

fclean:		clean
			@rm -f $(NAME)
			@echo "fclean Done!"
# Run clean (see above)
# Unconfirmed remove the library file.

re:			fclean all
# Run fclean (see above)
# Run all (see above)

.PHONY: all bonus clean fclean re