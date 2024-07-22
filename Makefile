# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviala <eviala@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 11:41:47 by eviala            #+#    #+#              #
#    Updated: 2024/07/20 12:54:39 by eviala           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme
NAME = so_long

# Dossier de sortie pour les fichiers objets
OBJ_DIR = obj/
SRCS_DIR = srcs/

# Dossiers des dépendances
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

# Les différentes bibliothèques
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a
MLX = $(MLX_DIR)/libmlx.a

MLX_FILE = libmlx.a
MLX_FLAG = -lX11 -lXext -lm
MLX_EX = $(MLX_LIB) $(MLX_FLAG)

# Headers et includes
HEADER = -I./includes \
	-I./libft/includes \
	-I./ft_printf/includes \
	-I./minilibx-linux/

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Commandes
CC = cc
RM = rm -rf

# Rechercher tous les fichiers .c dans le répertoire courant
SRCS = inits.c \
	map.c \
	so_long.c \
	checks.c \
	checks2.c \
	utils.c \
	events.c \
	floodfill.c \
	render.c \
	render_moves.c

MAKEFLAGS += --no-print-directory
TOTAL_FILES := $(words $(SRCS))
CURRENT_INDEX := 0

# Conversion des fichiers source en fichiers objets
OBJS = $(addprefix ${OBJ_DIR}, $(SRCS:.c=.o))
MLX_LIB = $(addprefix $(MLX_DIR), $(MLX_FILE))

# Cibles
all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "\n"

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)
	@echo "\n"

$(MLX):
	@echo "$(YELLOW)🔧 $(BLUE)$(BOLD)100% $(WHITE)$(BOLD)Compiling:$(WHITE)$(BOLD) $(MLX_FILE) $(RED)$(BOLD)							 $(MAGENTA)[ 31/ 31]$(RESET) \n"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

# Compilation de la bibliothèque
$(NAME): $(LIBFT) $(FT_PRINTF) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(HEADER) $(FT_PRINTF) $(LIBFT) $(MLX) $(MLX_FLAG)
	@echo "\n┗▷${BOLD}$(GREEN)『./$(NAME) Successfully created [✅]$(RESET)"

${OBJ_DIR}%.o: ${SRCS_DIR}%.c
	@mkdir -p $(dir $@)
	@$(eval CURRENT_INDEX=$(shell echo $$(($(CURRENT_INDEX)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_INDEX) * 100 / $(TOTAL_FILES)))))
	@printf "\r🔧 $(BLUE)$(BOLD)%3d%% $(WHITE)$(BOLD)Compiling:$(WHITE)$(BOLD) ${NAME}${RESET} $(RED)$(BOLD)%-50s $(MAGENTA)[%3d/%3d]$(RESET)" $(PERCENT) "$<" $(CURRENT_INDEX) $(TOTAL_FILES)
	@${CC} ${CFLAGS} ${HEADER} -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@echo "$(BOLD) [ 🗑️ ] $(YELLOW)$(REVERSED)Cleaning up$(RESET)"
	@$(MAKE) clean -C $(FT_PRINTF_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(MLX_DIR) > /dev/null 2>&1
	@$(RM) -r $(OBJ_DIR) > /dev/null 2>&1
	@echo "┗▷$(YELLOW)『$(ITALIC)./$(SRCS_DIR)'s$(RESET)$(YELLOW) object files cleaned』$(RESET)"

# Nettoyage complet
fclean: clean
	@$(MAKE) fclean -C $(FT_PRINTF_DIR) > /dev/null 2>&1
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(MLX_DIR) > /dev/null 2>&1
	@$(RM) $(NAME) > /dev/null 2>&1
	@echo "┗▷$(YELLOW)『$(ITALIC)./$(NAME)'s$(RESET)$(YELLOW)'s executables cleaned』$(RESET)"

# Recompiler entièrement
re: fclean
	$(MAKE) all

.PHONY: all clean fclean re

# ... (le reste du Makefile reste inchangé)
.SILENT:
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
