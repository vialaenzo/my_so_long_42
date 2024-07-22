# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviala <eviala@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 11:58:52 by eviala            #+#    #+#              #
#    Updated: 2024/07/16 11:36:16 by eviala           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme
NAME = ft_printf.a

# Dossier de sortie pour les fichiers objets
OBJ_DIR = obj/
SRCS_DIR = srcs/

# Headers et includes
HEADER = -I./includes

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Commandes
CC = cc
AR = ar rcs
RM = rm -rf

# Rechercher tous les fichiers .c dans le répertoire courant
SRCS		= ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putptr.c \
		ft_putnbr.c \
		ft_putunbr.c \
		ft_puthex.c

# Conversion des fichiers source en fichiers objets
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

TOTAL_FILES		:= $(words $(SRCS))
CURRENT_INDEX		:= 0

# Cibles
all: $(NAME)

# Compilation de la bibliothèque
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c | $(OBJ_DIR)
	@$(eval CURRENT_INDEX=$(shell echo $$(($(CURRENT_INDEX)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_INDEX) * 100 / $(TOTAL_FILES)))))
	@printf "\r🔧 $(BLUE)$(BOLD)%3d%% $(WHITE)$(BOLD)Compiling:$(WHITE)$(BOLD) ${NAME}${RESET} $(RED)$(BOLD)%-50s $(MAGENTA)[%3d/%3d]$(RESET)" $(PERCENT) "$<" $(CURRENT_INDEX) $(TOTAL_FILES)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets
clean:
	@echo "$(BOLD) [ 🗑️ ] $(YELLOW)$(REVERSED)Cleaning up$(RESET)"
	@$(RM) -r $(OBJ_DIR) > /dev/null 2>&1
	@echo "┗▷$(YELLOW)『$(ITALIC)./$(SRCS_DIR)'s$(RESET)$(YELLOW) object files cleaned』$(RESET)"

# Nettoyage complet
fclean: clean
	@$(RM) $(NAME) > /dev/null 2>&1
	@echo "┗▷$(YELLOW)『$(ITALIC)./$(NAME)'s$(RESET)$(YELLOW) executable cleaned』$(RESET)"

# Recompiler entièrement
re: fclean all

.PHONY: all clean fclean re

# Colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m
RESET := \033[0m
BOLD := \033[1m
UNDERLINE := \033[4m
REVERSED := \033[7m
ITALIC := \033[3m
