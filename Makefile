#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

NAME		=	minirt

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
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g
RM			=	rm -rf
MLXLIBA		=	include/MLX42/build/libmlx42.a

# Sources are all .c files
SRC_DIR		=	src/
SRCS		=	main.c vector.c

OBJS_DIR	=	obj/
OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: mlx $(OBJS_DIR) $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MLXLIBA) -I include -lglfw -L "/USERS/$(USER)/.brew/opt/glfw/lib/" $(OBJS) -o $(NAME)
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
