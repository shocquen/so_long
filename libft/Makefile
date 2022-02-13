# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 09:28:22 by shocquen          #+#    #+#              #
#    Updated: 2022/02/08 15:03:33 by shocquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define compiling
	@echo "$(shell tput bold)$(shell tput setaf 3)Compiling $1 $(shell tput sgr0)\c"
	@$(CC) $(CFLAGS) -I$(INC) -c $1 -o $2
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define finishing
	@echo "$(shell tput bold)$(shell tput setaf 2)Compiling $1 $(shell tput sgr0)\c"
	@$(AR) $(NAME) $(addprefix obj/, $(OBJS))
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

define removing
	@echo "$(shell tput bold)$(shell tput setaf 8)Removing $1 $(shell tput sgr0)\c"
	@$(RM) $1  > /dev/null 
	@echo "$(shell tput bold)$(shell tput setaf 2)√$(shell tput sgr0)"
endef

CC =		gcc
NAME =		libft.a

BASE = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c 

PRINTF = ft_lennb.c \
ft_print_c.c \
ft_print_cap_x.c \
ft_print_di.c \
ft_print_p.c \
ft_print_percent.c \
ft_print_s.c \
ft_print_u.c \
ft_print_x.c \
ft_printf.c \
ft_putchar.c \
ft_putnbr_base.c 

GNL = get_next_line.c \
get_next_line_utils.c 

SRCS =	$(BASE) $(PRINTF) $(GNL)

OBJS =		$(SRCS:.c=.o)

INC =		./includes

RM =		rm -rf
AR =		ar -rcs
CFLAG =	-Wall -Wextra -Werror

${NAME}:	$(addprefix obj/, $(OBJS))
			$(call finishing,$(NAME))

obj/%.o: src/**%.c
			@mkdir -p $(@D)
			$(call compiling,$<,$@,0)

all:		$(NAME)

clean:
			$(call removing,obj)

fclean:	clean
			$(call removing,$(NAME))

re: 		fclean all

.PHONY : 	all clean fclean re