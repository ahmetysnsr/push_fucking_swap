# 42-style Makefile for push_swap (WSL/Linux)

# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
# Enable dependency generation
DFLAGS  := -MMD -MP

# Target
NAME	:= push_swap
CHECKER	:= checker

# Directories
OBJDIR 		:= obj
WRAPPER_DIR	:= push_swap_wrappers
PRINTF_DIR	:= ft_printf

PRINTF_LIB	:= $(PRINTF_DIR)/libftprintf.a
LIBS		:= -L$(PRINTF_DIR) -lftprintf

# Sources
# Root sources
ROOT_SRCS := \
	input_functions.c \
	linked_list_add_functions.c \
	linked_list_init_functions.c \
	linked_list_printer.c \
	linked_list_remove_functions.c \
	linked_list_utils.c \
	linked_list_sort_functions.c \
	push_swap_functions.c \
	ft_split.c \
	main.c

# Wrapper sources (Manually listed)
# BURADAKİ DOSYA İSİMLERİNİ GERÇEK İSİMLERLE DEĞİŞTİRİN
WRAPPER_SRCS := \
	$(WRAPPER_DIR)/push_functions.c \
	$(WRAPPER_DIR)/reverse_rotate_functions.c \
	$(WRAPPER_DIR)/swap_functions.c \
	$(WRAPPER_DIR)/rotate_functions.c \

# All sources combined
SRCS := $(ROOT_SRCS) $(WRAPPER_SRCS)

# Checker sources
CHECKER_ROOT_SRCS := \
	input_functions.c \
	linked_list_add_functions.c \
	linked_list_init_functions.c \
	linked_list_remove_functions.c \
	linked_list_utils.c \
	linked_list_sort_functions.c \
	push_swap_functions.c \
	ft_split.c \
	checker.c

CHECKER_SRCS := $(CHECKER_ROOT_SRCS) $(WRAPPER_SRCS)

# Objects
OBJS			:= $(SRCS:%.c=$(OBJDIR)/%.o)
CHECKER_OBJS	:= $(CHECKER_SRCS:%.c=$(OBJDIR)/%.o)
DEPS			:= $(OBJS:.o=.d) $(CHECKER_OBJS:.o=.d)

# Default rule
all: $(NAME)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)


checker: $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER)

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# Object build rule with deps and auto-mkdir for subdirectories
$(OBJDIR)/%.o: %.c push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

# Include dependencies
-include $(DEPS)

# Convenience targets
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re checker