# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/06 15:47:34 by jjacobi           #+#    #+#              #
#    Updated: 2017/10/19 19:32:23 by jjacobi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

SRC_FILES   = main.c read_file.c build_connections.c treatment.c
OBJ			= $(SRC_FILES:.c=.o)

H_DIRS		= -I ./includes -I ./libft/includes -I ./libmlx
SRC_FOLDER	= ./srcs
LIBFT_PATH	= ./libft
MLX_PATH	= ./libmlx

GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m

ifeq ($(shell uname),Darwin)
	ECHO	= echo
else
	ECHO	= echo -e
endif

all: $(NAME)

$(NAME): $(OBJ)
	@$(ECHO) "\r$(GREEN) The .o from $(NAME) are compiled.            \
                                                    $(DEFAULT)"
	@($(MAKE) -C $(LIBFT_PATH))
	@($(MAKE) -C $(MLX_PATH))
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_PATH)/libft.a $(MLX_PATH)/libmlx.a \
			$(H_DIRS) -framework OpenGL -framework AppKit
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

re: fclean all

.PHONY: clean fclean re all
