# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 19:58:37 by vodebunm          #+#    #+#              #
#    Updated: 2024/07/21 14:26:26 by vodebunm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
SRCDIR = srcs
OBJDIR = objs
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Libraries
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FTPRINTF_DIR = ft_printf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a
MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a
CFLAGS = -Iincludes
# Include directories
INCLUDES = -I$(LIBFT_DIR) -I$(FTPRINTF_DIR) -I$(MINILIBX_DIR)

# Library flags
LIBS = -L$(LIBFT_DIR) -lft -L$(FTPRINTF_DIR) -lftprintf -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(FTPRINTF) $(MINILIBX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	@if [ -d "$(LIBFT_DIR)" ]; then \
		make -C $(LIBFT_DIR); \
	else \
		echo "Directory $(LIBFT_DIR) not found."; \
		exit 1; \
	fi

$(FTPRINTF):
	@if [ -d "$(FTPRINTF_DIR)" ]; then \
		make -C $(FTPRINTF_DIR); \
	else \
		echo "Directory $(FTPRINTF_DIR) not found."; \
		exit 1; \
	fi

$(MINILIBX_LIB):
	@if [ -d "$(MINILIBX_DIR)" ]; then \
		make -C $(MINILIBX_DIR); \
	else \
		echo "Directory $(MINILIBX_DIR) not found."; \
		exit 1; \
	fi

clean:
	rm -rf $(OBJDIR)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		make -C $(LIBFT_DIR) clean; \
	fi
	@if [ -d "$(FTPRINTF_DIR)" ]; then \
		make -C $(FTPRINTF_DIR) clean; \
	fi
	@if [ -d "$(MINILIBX_DIR)" ]; then \
		make -C $(MINILIBX_DIR) clean; \
	fi

fclean: clean
	rm -f $(NAME)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		make -C $(LIBFT_DIR) fclean; \
	fi
	@if [ -d "$(FTPRINTF_DIR)" ]; then \
		make -C $(FTPRINTF_DIR) fclean; \
	fi
	@if [ -d "$(MINILIBX_DIR)" ]; then \
		make -C $(MINILIBX_DIR) clean; \
	fi

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(FTPRINTF) $(MINILIBX_LIB)
