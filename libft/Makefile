# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 11:02:51 by jjacobi           #+#    #+#              #
#    Updated: 2017/04/21 20:40:23 by jjacobi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libft.a
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror

LIBFT_SRCS_FILES	= ft_putchar.c ft_putstr.c ft_strlen.c ft_putchar_fd.c \
						ft_putstr_fd.c ft_strnew.c ft_strdel.c ft_memdel.c \
						ft_memalloc.c ft_strclr.c ft_striter.c ft_striteri.c \
						ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
						ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
						ft_itoa.c ft_putendl.c ft_putnbr.c ft_putendl_fd.c \
						ft_putnbr_fd.c ft_tolower.c ft_toupper.c ft_isprint.c \
						ft_isascii.c ft_isalnum.c ft_isalpha.c ft_isdigit.c \
						ft_atoi.c ft_strncmp.c ft_strcmp.c ft_strstr.c \
						ft_strnstr.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
						ft_strcat.c ft_strncat.c ft_strlcat.c ft_memcpy.c \
						ft_strchr.c ft_strrchr.c ft_memset.c ft_bzero.c \
						ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
						ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
						ft_lstiter.c ft_lstmap.c ft_sqrt.c ft_power.c \
						ft_split_whitespaces.c ft_sort_wordtab.c ft_lstsort.c \
						get_next_line.c ft_itoa_base.c
LIBFT_OBJS			= $(addprefix \
							$(LIBFT_SRCS_FOLDER), $(LIBFT_SRCS_FILES:.c=.o))
PRINTF_SRCS_FILES	= ft_printf.c stock_info.c parse_info.c parse_s.c \
						parse_maj_s.c parse_p.c parse_d.c parse_maj_d.c \
						parse_i.c parse_o.c parse_maj_o.c parse_u.c \
						parse_maj_u.c parse_x.c parse_maj_x.c parse_c.c \
						parse_maj_c.c parse_percent.c utils.c unsigned_itoa.c \
						parse_noconv.c ft_dprintf.c
PRINTF_OBJS			= $(addprefix \
							$(PRINTF_SRCS_FOLDER), $(PRINTF_SRCS_FILES:.c=.o))

H_DIR				= ./includes/
LIBFT_SRCS_FOLDER	= ./srcs/libft/
PRINTF_SRCS_FOLDER	= ./srcs/ft_printf/

GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m

ifeq ($(shell uname),Darwin)
	ECHO = echo
else
	ECHO = echo -e
endif

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(PRINTF_OBJS)
	@$(ECHO) "\r$(GREEN) The .o from $(NAME) are compiled.            \
                                                    \c$(DEFAULT)"
	@ar rc $@ $^
	@ar -s $@
	@$(ECHO) "\n$(GREEN)$(NAME)$(DEFAULT) created."

%.o: 
	@$(ECHO) "\r$(GREEN) Compiling $@                      \c\033[K"
	@$(CC) $(CFLAGS) -c -o $@ $(@:.o=.c) -I $(H_DIR)

clean:
	@rm -rf $(LIBFT_OBJS) $(PRINTF_OBJS)
	@$(ECHO) "All $(RED).o$(DEFAULT) are now deleted for $(NAME)."

fclean: clean
	@rm -rf $(NAME)
	@$(ECHO) "$(RED)$(NAME)$(DEFAULT) is now deleted."

re: fclean all

.PHONY: clean fclean re all
