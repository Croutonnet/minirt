#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

NAME		=	minirt
OS := $(shell uname -s)

# Style
BOLD		=	\033[1m
ITALIC		=	\033[3m
UNDERLINE	=	\033[4m

# Color text
RESET		=	\033[0m
BLACK		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PURPLE		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
DEFAULT		=	\033[39m
ERASE_LINE	=	\033[2K\r

# Compiler and flags
CC				=	gcc
CFLAGS			=	-g #-Wall -Werror -Wextra
RM				=	rm -rf
MLXLIBA			=	include/MLX42/build/libmlx42.a
LIBFTA			=	include/Libft/libft.a
LIBFT_DIR		=	include/Libft/
LIBFT_GIT_URL	=	https://github.com/Croutonnet/Libft.git
LIBFT_VERSION	=	v2.0.0

# Sources are all .c files
SRC_DIR		=	src/
SRCS		=	main.c ray.c sphere.c vector_math.c vector.c cylinder.c parsing.c parsing_utils.c line_read.c

OBJS_DIR	=	obj/
OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

ifeq ($(OS),Linux) # règles en + pour Linux
    LIBS = -ldl -lglfw -pthread -lm
endif

all: libft mlx $(OBJS_DIR) $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I include -lglfw -L "/USERS/$(USER)/.brew/opt/glfw/lib/" $(OBJS) -o $(NAME) $(MLXLIBA) $(LIBFTA) $(LIBS)
	@echo "$(ERASE_LINE)$(GREEN)✔️ $(ITALIC)$(NAME) successfully compile.$(RESET)\
	$(GREEN) ✔️$(RESET)"

# create objects directory
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Removes objects
clean:
	@printf "💣 $(RED)Removing $(NAME) objects and MLX42... $(RESET) 💥\n"
	@$(RM) $(OBJS_DIR)
	@$(RM) include/MLX42/build

# Removes objects and executables
fclean: clean
	@printf "💣 $(RED)Removing $(NAME) executable$(RESET) 💥\n"
	@$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
	@echo "$(ERASE_LINE)$(GREEN)✔️ $(ITALIC)Remake complete$(RESET)\
	$(GREEN) ✔️$(RESET)"

mlx:
	@if [ ! -d "include/MLX42/" ]; then \
        echo "libmlx directory does not exist, cloning..."; \
        git clone -b v2.3.2 -q https://github.com/codam-coding-college/MLX42.git include/MLX42/; \
	fi
	@cmake include/MLX42/ -B include/MLX42/build/ && make -C include/MLX42/build/ -j4

libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
        echo "libft directory does not exist, cloning..."; \
        git clone -b $(LIBFT_VERSION) -q $(LIBFT_GIT_URL) $(LIBFT_DIR); \
	fi
	@$(MAKE) -sC $(LIBFT_DIR)

# Permet de rediriger l'affichage graphique vers Xserver sous wsl
#export DISPLAY=$(ip route list default | awk '{print $3}'):0
#export LIBGL_ALWAYS_INDIRECT=0
