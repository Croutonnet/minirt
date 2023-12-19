#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

NAME		=	libft.a
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
CFLAGS			=	-g -Wall -Werror -Wextra
RM				=	rm -rf

# Sources are all .c files
CHAR_DIR	=	src/character/
SRCS_CHAR	=	ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\

PRINTF_DIR	=	src/ft_printf/
SRCS_PRINTF	=	ft_printf_fd.c\
				ft_printfc_fd.c\
				ft_printfd_fd.c\
				ft_printfp_fd.c\
				ft_printfs_fd.c\
				ft_printfu_fd.c\
				ft_printfx_fd.c\
				ft_printfxx_fd.c\

GNL_DIR		=	src/gnl/
SRCS_GNL	=	get_next_line.c

LIST_DIR	=	src/list/
SRCS_LIST	=	ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c

MEM_DIR		=	src/mem/
SRCS_MEM	=	ft_bzero.c\
				ft_calloc.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_realloc.c\
				ft_xfree.c\
				ft_xxfree.c

NUMBER_DIR	=	src/number/
SRCS_NUMBER	=	ft_atof.c\
				ft_atoi.c\
				ft_itoa.c\

STRING_DIR	=	src/string/
SRCS_STRING	=	ft_searchstr.c\
				ft_split.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c\

WRITE_DIR	=	src/write/
SRCS_WRITE	=	ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c


OBJS_DIR	=	obj/
OBJS_CHAR		=	$(addprefix $(OBJS_DIR), $(SRCS_CHAR:.c=.o))
OBJS_PRINTF		=	$(addprefix $(OBJS_DIR), $(SRCS_PRINTF:.c=.o))
OBJS_GNL		=	$(addprefix $(OBJS_DIR), $(SRCS_GNL:.c=.o))
OBJS_LIST		=	$(addprefix $(OBJS_DIR), $(SRCS_LIST:.c=.o))
OBJS_MEM		=	$(addprefix $(OBJS_DIR), $(SRCS_MEM:.c=.o))
OBJS_NUMBER		=	$(addprefix $(OBJS_DIR), $(SRCS_NUMBER:.c=.o))
OBJS_STRING		=	$(addprefix $(OBJS_DIR), $(SRCS_STRING:.c=.o))
OBJS_WRITE		=	$(addprefix $(OBJS_DIR), $(SRCS_WRITE:.c=.o))

OBJS = $(OBJS_CHAR) $(OBJS_PRINTF) $(OBJS_GNL) $(OBJS_LIST) $(OBJS_MEM) $(OBJS_NUMBER) $(OBJS_STRING) $(OBJS_WRITE)

$(OBJS_DIR)%.o: $(CHAR_DIR)%.c
	@printf "$(ERASE_LINE)⚙️ $(PURPLE)Compiling $(DEFAULT)⚙️$(YELLOW) $(notdir $<)\
	$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_DIR)%.o: $(PRINTF_DIR)%.c
	@printf "$(ERASE_LINE)⚙️ $(PURPLE)Compiling $(DEFAULT)⚙️$(YELLOW) $(notdir $<)\
	$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_DIR)%.o: $(GNL_DIR)%.c
	@printf "$(ERASE_LINE)⚙️ $(PURPLE)Compiling $(DEFAULT)⚙️$(YELLOW) $(notdir $<)\
	$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_DIR)%.o: $(LIST_DIR)%.c
	@printf "$(ERASE_LINE)⚙️ $(PURPLE)Compiling $(DEFAULT)⚙️$(YELLOW) $(notdir $<)\
	$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_DIR)%.o: $(MEM_DIR)%.c
	@printf "$(ERASE_LINE)⚙️ $(PURPLE)Compiling $(DEFAULT)⚙️$(YELLOW) $(notdir $<)\
	$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_DIR)%.o: $(NUMBER_DIR)%.c
	@printf "$(ERASE_LINE)⚙️ $(PURPLE)Compiling $(DEFAULT)⚙️$(YELLOW) $(notdir $<)\
	$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_DIR)%.o: $(STRING_DIR)%.c
	@printf "$(ERASE_LINE)⚙️ $(PURPLE)Compiling $(DEFAULT)⚙️$(YELLOW) $(notdir $<)\
	$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_DIR)%.o: $(WRITE_DIR)%.c
	@printf "$(ERASE_LINE)⚙️ $(PURPLE)Compiling $(DEFAULT)⚙️$(YELLOW) $(notdir $<)\
	$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

all: dir $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@printf "$(ERASE_LINE)$(GREEN)✔️ $(ITALIC)$(NAME) successfully compile.$(RESET)\
	$(GREEN) ✔️$(RESET)"

# create objects directory
dir:
	@mkdir -p $(OBJS_DIR)

# Removes objects
clean:
	@printf "💣 $(RED)Removing $(NAME) objects $(RESET) 💥\n"
	@$(RM) $(OBJS_DIR)

# Removes objects and executables
fclean: clean
	@printf "💣 $(RED)Removing $(NAME) executable$(RESET) 💥\n"
	@$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
	@printf "$(ERASE_LINE)$(GREEN)✔️ $(ITALIC)Remake complete$(RESET)\
	$(GREEN) ✔️$(RESET)"
