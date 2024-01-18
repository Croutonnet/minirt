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

SRC_DIR		=	src/
SRCS		=	main.c\
				ray.c\
				sphere.c\
				vector_math.c\
				vector.c\
				vector2.c\
				cylinder.c\
				final_viewport.c\
				plane.c\

PARS_DIR	=	src/parsing/
SRCS_PARS	=	line_read.c\
				line_read_utils.c\
				parsing.c\
				parsing_utils.c\
				parsing_func.c\
				check_file.c\
				read_map.c\
				create_shape.c\
				collision.c

MOUV_DIR	=	src/mouvement/
SRCS_MOUV	=	rotation.c\
				cam_mouvement.c\
				more_obj_mouvement.c\
				obj_mouvement.c\
				object_intersect.c

OBJS_DIR	=	obj/
OBJSBASE	=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJSPARS	=	$(addprefix $(OBJS_DIR), $(SRCS_PARS:.c=.o))
OBJSMOUV	=	$(addprefix $(OBJS_DIR), $(SRCS_MOUV:.c=.o))

OBJS		=	$(OBJSBASE) $(OBJSPARS) $(OBJSMOUV)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_DIR)%.o: $(PARS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_DIR)%.o: $(MOUV_DIR)%.c
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

# $(NAME): $(OBJS)
# 	@$(CC) $(CFLAGS) -I include -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.9/lib" $(OBJS) -o $(NAME) $(MLXLIBA) $(LIBFTA) $(LIBS)
# 	@echo "$(ERASE_LINE)$(GREEN)✔️ $(ITALIC)$(NAME) successfully compile.$(RESET)\
# 	$(GREEN) ✔️$(RESET)"

# create objects directory
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Removes objects
clean:
	@printf "💣 $(RED)Removing $(NAME) objects and MLX42... $(RESET) 💥\n"
	@cd include/Libft/ && make clean && cd ..
	@$(RM) $(OBJS_DIR)
	@$(RM) include/MLX42/build

# Removes objects and executables
fclean: clean
	@printf "💣 $(RED)Removing $(NAME) executable$(RESET) 💥\n"
	@$(RM) $(NAME)
	@cd include/Libft/ && $(RM) libft.a && cd ..

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
        git clone -q $(LIBFT_GIT_URL) $(LIBFT_DIR); \
	fi
	@$(MAKE) -sC $(LIBFT_DIR)

fclean_run:
	@printf "💣 $(RED)Removing $(NAME) objects $(RESET) 💥\n"
	@$(RM) $(OBJS_DIR)
	@printf "💣 $(RED)Removing $(NAME) executable$(RESET) 💥\n"
	@$(RM) $(NAME)

run : fclean_run all
	@printf "$(ERASE_LINE)$(GREEN)✔️ $(RED)$(ITALIC)$(NAME) LAUNCHING🚀!!!!!!$(RESET)\
	$(GREEN) ✔️$(RESET)\n"
	@./minirt map/test.rt


# Permet de rediriger l'affichage graphique vers Xserver sous wsl
#export DISPLAY=$(ip route list default | awk '{print $3}'):0
#export LIBGL_ALWAYS_INDIRECT=0
