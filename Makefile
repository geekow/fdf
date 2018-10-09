# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/06 15:47:34 by jjacobi           #+#    #+#              #
#    Updated: 2018/10/10 00:24:00 by jjacobi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g

SRC_FILES   = main.c read_file.c build_connections.c treatment.c key_parser.c \
			  trace_line.c
OBJ			= $(SRC_FILES:.c=.o)

H_DIRS		= -I ./includes -I ./libft/includes
SRC_FOLDER	= ./srcs
LIBFT_PATH	= ./libft
ifeq ($(shell uname),Darwin)
	MLX_PATH	= ./libmlx_macos
	CC_FLAGS	= -I ./libmlx_macos -framework OpenGL -framework AppKit
	ECHO	= echo
else
	MLX_PATH	= ./libmlx_linux
	CC_FLAGS	= -I ./libmlx_linux -I /usr/X11/include -g -L /usr/X11/lib \
				  -lX11 -lmlx -lXext -lm
	ECHO	= echo -e
endif

GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m

all: $(NAME)

$(NAME): $(OBJ)
	@$(ECHO) "\r$(GREEN) The .o from $(NAME) are compiled.            \
                                                    $(DEFAULT)"
	@($(MAKE) -C $(LIBFT_PATH))
	@($(MAKE) -C $(MLX_PATH))
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_PATH)/libft.a $(MLX_PATH)/libmlx.a \
			$(H_DIRS) $(CC_FLAGS)
	@$(ECHO) "$(GREEN)$(NAME)$(DEFAULT) created."

%.o: $(SRC_FOLDER)/%.c
	@$(ECHO) "\r$(GREEN) Compiling $@                      \c\033[K"
	@$(CC) $(CFLAGS) -c -o $@ $< $(H_DIRS)

clean:
	@rm -rf $(OBJ)
	@$(ECHO) "All $(RED).o$(DEFAULT) are now deleted for $(NAME)."
	@($(MAKE) -C $(LIBFT_PATH) $@)
	@($(MAKE) -C $(MLX_PATH) $@)

fclean:
	@rm -rf $(NAME) $(OBJ)
	@$(ECHO) "All $(RED).o$(DEFAULT) are now deleted for $(NAME)."
	@$(ECHO) "$(RED)$(NAME)$(DEFAULT) is now deleted."
	@($(MAKE) -C $(LIBFT_PATH) $@)
	@($(MAKE) -C $(MLX_PATH) clean)

re: fclean all

.PHONY: clean fclean re all
