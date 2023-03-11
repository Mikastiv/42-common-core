# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 10:49:05 by mleblanc          #+#    #+#              #
#    Updated: 2021/09/24 22:31:13 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRC			=	src
INC			=	include
OBJ			=	obj

HFILES		=	philo.h utils.h
HEADERS		=	$(addprefix $(INC)/, $(HFILES))

CFILES		=	main.c parse.c utils.c routine.c init_and_destroy.c queue.c philo.c
OFILES		=	$(CFILES:.c=.o)
OBJS		=	$(addprefix $(OBJ)/, $(OFILES))
SRCS		=	$(addprefix $(SRC)/, $(CFILES))

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -O2
RM			=	rm -rf

VPATH		= $(SRC)

$(OBJ)/%.o:	%.c
			$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME):	$(OBJ) $(OBJS)
			$(CC) $(OBJS) -lpthread -o $(NAME)

$(OBJ):
			@mkdir -p $(OBJ)

all:		$(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

norme:
			@norminette $(SRCS) $(HEADERS)

.PHONY:		all clean fclean re norme
