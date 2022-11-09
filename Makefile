# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kblok <kblok@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/16 20:46:21 by kblok         #+#    #+#                  #
#    Updated: 2022/11/08 11:39:36 by kblok         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#==============================================================================: Filename
NAME		= 	fdf

#==============================================================================: Source to object conversion 
OBJS		= 	$(SRCS:srcs/%.c=objs/%.o)

#==============================================================================: Compile variables
CC			= 	gcc
CFLAGS		= 	-g -Wall -Werror -Wextra
RM			=	rm -rf
AR			=	ar rcs
MKDIR		=	mkdir -p objs
HEADERS		= 	-I $(FDF) -I $(MLX42) -I $(LIBFT)

#==============================================================================: Include files
FDF			=	includes/
LIBFT		= 	includes/libft/
MLX42		=	includes/MLX42/

#==============================================================================: Source files 
SRCS		=	$(addprefix srcs/, \
				coordinates.c \
				draw_line.c \
				error.c \
				main.c \
				parsing.c \
				projection.c \
				rendering.c \
				)

#==============================================================================: GLFW
GLFW = -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

#==============================================================================: Color codes
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

#==============================================================================: Make commands
all: message includes $(NAME)

#==============================================================================: Main compile
$(NAME): $(OBJS)
	
	@$(CC) $(OBJS) $(GLFW) $(HEADERS) $(LIBFT)libft.a $(MLX42)libmlx42.a -o $(NAME)
	@echo "$(GREEN)✅Done compiling $(NAME)$(RESET)"

#==============================================================================: File compile
objs/%.o: srcs/%.c
	@$(MKDIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
ifeq ($(DB),1)
	@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
endif

#==============================================================================: Executable run command
run: all
	@./$(NAME) maps/$(MAP).fdf

#==============================================================================: Compile includes
includes:
	@$(MAKE) -C $(MLX42)
	@$(MAKE) -C $(LIBFT)

#==============================================================================: Build messages
message:
	@echo "$(BLUE)🔨Creating object folder$(RESET)"
	@echo "$(GREEN)🔨Compiling: $(MAGENTA)$(NAME)...$(RESET)"

#==============================================================================: Remove all object files
clean:
	@$(RM) objs/
	@$(MAKE) clean -C $(LIBFT)
	@$(MAKE) clean -C $(MLX42)
	@echo "$(RED)🧹Cleaned object folders!$(RESET)"

#==============================================================================: Remove object files and executables
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT)
	@$(MAKE) fclean -C $(MLX42)
	@echo "$(RED)🧹Cleaned $(NAME)!$(RESET)"

#==============================================================================: Remove object files and executables then remake executables
re: fclean all

.PHONY: all clean fclean re message includes run objs