# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 11:52:24 by mleblanc          #+#    #+#              #
#    Updated: 2021/07/19 12:54:02 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		=	client
SERVER		=	server

SRC			=	src
INC			=	include
OBJ			=	obj

FTDIR		=	libft
LIBFT		=	ft
MAKELIBFT	=	$(MAKE) --no-print-directory -C $(FTDIR)

CFILES_C	=	client.c
OBJS_C		=	$(addprefix $(OBJ)/, $(CFILES_C:.c=.o))

CFILES_S	=	server.c
OBJS_S		=	$(addprefix $(OBJ)/, $(CFILES_S:.c=.o))

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -O3
RM			=	rm -rf

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -I. -c $< -o $@

all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJ) $(OBJS_C)
			@$(MAKELIBFT)
			$(CC) $(OBJS_C) -L$(FTDIR) -l$(LIBFT) -o $(CLIENT)

$(SERVER):	$(OBJ) $(OBJS_S)
			@$(MAKELIBFT)
			$(CC) $(OBJS_S) -L$(FTDIR) -l$(LIBFT) -o $(SERVER)

$(OBJ):
			@mkdir -p $(OBJ)

clean:
			@$(MAKELIBFT) clean
			@$(RM) $(OBJS_C) $(OBJS_S)

fclean:		clean
			@$(MAKELIBFT) fclean
			@$(RM) $(CLIENT) $(SERVER)

re:			fclean all

bonus:		all

.PHONY:		all clean fclean re bonus
