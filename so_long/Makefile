NAME		= so_long

LIBMLX		= mlx
LIBFT		= ft
FTDIR		= libft
MAKELIBFT	= $(MAKE) -C $(FTDIR)

INCDIR		= include
SRCDIR		= src
CFILES		= main.c map.c map_validation.c map_validation2.c map_validation3.c buffer.c\
			game.c sprite.c render.c map2.c player.c
HFILES		= map.h map_validation.h buffer.h game.h sprite.h render.h player.h
INCS		= $(addprefix $(INCDIR)/, $(HFILES))
SRCS		= $(addprefix $(SRCDIR)/, $(CFILES))
OBJS		= $(SRCS:.c=.o)

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

%.o:		%.c
			$(CC) $(CFLAGS) -I$(FTDIR) -I$(INCDIR) -c $< -o $@

$(NAME):	$(OBJS)
			$(MAKELIBFT)
			$(CC) $(CFLAGS) $(OBJS) -L$(FTDIR) -l$(LIBFT) -l$(LIBMLX) -framework OpenGL -framework AppKit -o $(NAME)

all:		$(NAME)

clean:
			$(MAKELIBFT) clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKELIBFT) fclean
			$(RM) $(NAME)

re:			fclean all

norme:
			$(MAKELIBFT) norme
			norminette $(SRCS) $(INCS)

.PHONY:		all clean fclean re norme