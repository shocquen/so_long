# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 09:28:22 by shocquen          #+#    #+#              #
#    Updated: 2022/02/17 15:31:16 by shocquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define sign
	@clear
	@tput setaf 1
	@tput bold

	@sleep .1
	@echo "$(shell tput cup 0 0)..%%%%...%%..%%...%%%%....%%%%....%%%%%...%%%%...%%%%%%..%%..%%."	
	@sleep .2

	@echo "$(shell tput cup 0 0).....%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%......%%..%%."
	@echo "$(shell tput cup 1 0)..%%%%...%%..%%...%%%%....%%%%....%%%%%...%%%%...%%%%%%..%%..%%."	
	@sleep .15

	@echo "$(shell tput cup 0 0)..%%%%...%%%%%%..%%..%%..%%......%%.%%%..%%..%%..%%%%....%%.%%%."
	@echo "$(shell tput cup 1 0).....%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%......%%..%%."
	@echo "$(shell tput cup 2 0)..%%%%...%%..%%...%%%%....%%%%....%%%%%...%%%%...%%%%%%..%%..%%."	
	@sleep .2

	@echo "$(shell tput cup 0 0).%%......%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%......%%%.%%."
	@echo "$(shell tput cup 1 0)..%%%%...%%%%%%..%%..%%..%%......%%.%%%..%%..%%..%%%%....%%.%%%."
	@echo "$(shell tput cup 2 0).....%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%......%%..%%."
	@echo "$(shell tput cup 3 0)..%%%%...%%..%%...%%%%....%%%%....%%%%%...%%%%...%%%%%%..%%..%%."	
	@sleep .2

	@echo "$(shell tput cup 0 0)..%%%%...%%..%%...%%%%....%%%%....%%%%...%%..%%..%%%%%%..%%..%%."
	@echo "$(shell tput cup 1 0).%%......%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%......%%%.%%."
	@echo "$(shell tput cup 2 0)..%%%%...%%%%%%..%%..%%..%%......%%.%%%..%%..%%..%%%%....%%.%%%."
	@echo "$(shell tput cup 3 0).....%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%..%%......%%..%%."
	@echo "$(shell tput cup 4 0)..%%%%...%%..%%...%%%%....%%%%....%%%%%...%%%%...%%%%%%..%%..%%."	
	@sleep .1

	@tput sgr0
endef

# Create a library
define creating
	@echo "$(shell tput bold)$(shell tput setaf 2)Create $1 $(shell tput sgr0)\c"
	@$(AR) $(NAME) $(addprefix obj/, $(OBJS))
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

# Call another Makefile
define making
	@echo "$(shell tput setaf 6)Make $1 $(shell tput sgr0)\c"
	@make -C $1 > /dev/null 2> /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

# Compile src/file.c to obj/file.o
define compiling
	@echo "$(shell tput bold)$(shell tput setaf 3)Compiling $1 $(shell tput sgr0)\c"
	@$(CC) $(CFLAGS) -I$(INC) -c $1 -o $2
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

# Compile the executable
define finishing
	@echo "$(shell tput bold)$(shell tput setaf 2)Compiling $1 $(shell tput sgr0)\c"
	@$(CC) $(CFLAGS) $(addprefix obj/, $(OBJS)) $(LIBS) -I$(INC) $(MLXFLAGS) -o $(NAME)
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define cleaning
	@echo "$(shell tput bold)$(shell tput setaf 8)$2 $1 $(shell tput sgr0)\c"
	@make $2 -C $1 > /dev/null
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define removing
	@echo "$(shell tput bold)$(shell tput setaf 8)Removing $1 $(shell tput sgr0)\c"
	@$(RM) $1  > /dev/null 
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

# SRCS			= test.c
SRCS		= main.c \
 	map_checks.c \
	print.c \
	moves.c \
	hooks.c \
	apply_map.c \
	init.c \
	map_utils.c \
	end_game.c \
	collects_manager.c

OBJS		= $(SRCS:.c=.o)

INC		= ./includes

LIBS	=	./libmlx/libmlx.a ./libft/libft.a

NAME		= so_long
RM			= rm -rf
CC			= gcc
AR			= ar -rcs
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -Ilibmlx -Llibmlx -llibmlx -framework OpenGL -framework AppKit

ifeq ($(shell uname),Linux)
MLXFLAGS	= -Ilibmlx -lXext -lX11 -lm -lz
endif

${NAME}:	signe $(addprefix obj/, $(OBJS))
			$(call making,libft)
			$(call making,libmlx)
			$(call finishing,$(NAME))

obj/%.o:	src/%.c
			@mkdir -p $(@D)
			$(call compiling,$<,$@,0)

all:	 $(NAME)

clean:	
			$(call cleaning,libft,clean)
			$(call cleaning,libmlx,clean)
			$(call removing,obj)

fclean:		clean
			$(call cleaning,libft,fclean)
			$(call removing,$(NAME))

re:			fclean all

signe:
			$(call sign)
			@echo

.PHONY : 	all clean fclean re
