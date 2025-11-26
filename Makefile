# 42-style Makefile for push_swap (WSL/Linux)

# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -I.
# Enable dependency generation
DFLAGS  := -MMD -MP

# Target
NAME    := push_swap
CHECKER := checker

# Sources (all .c in repo root)
SRCS := \
    input_functions.c \
    linked_list_add_functions.c \
    linked_list_init_functions.c \
    linked_list_printer.c \
    linked_list_remove_functions.c \
	linked_list_utils.c \
    linked_list_sort_functions.c \
    push_swap_functions.c \
    push_swap_wrapper_functions.c \
    main.c

# Checker sources (no wrapper prints needed, but reuse shared modules)
CHECKER_SRCS := \
	input_functions.c \
	linked_list_add_functions.c \
	linked_list_init_functions.c \
	linked_list_remove_functions.c \
	linked_list_utils.c \
	linked_list_sort_functions.c \
	push_swap_functions.c \
	checker.c

CHECKER_OBJS := $(CHECKER_SRCS:%.c=$(OBJDIR)/%.o)

# Build directories
OBJDIR  := obj
OBJS    := $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS    := $(OBJS:.o=.d)

# Default rule
all: $(NAME)

checker: $(OBJDIR) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER)
	@echo "Built $(CHECKER)"

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "Built $(NAME)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Object build rule with deps
$(OBJDIR)/%.o: %.c push_swap.h | $(OBJDIR)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

# Convenience targets
clean:
	@rm -rf $(OBJDIR)
	@echo "Cleaned objects"

fclean: clean
	@rm -f $(NAME)
	@echo "Removed $(NAME)"

re: fclean all

# Build with debug info
.PHONY: debug
debug: CFLAGS += -g3 -O0
debug: re

# Build with AddressSanitizer (Linux/Clang or GCC)
.PHONY: sanitize
sanitize: CFLAGS += -g3 -O0 -fsanitize=address -fno-omit-frame-pointer
sanitize: re

# Run helper: make run ARGS="3 2 1"
.PHONY: run
run: $(NAME)
	./$(NAME) $(ARGS)

# Basic help
.PHONY: help
help:
	@echo "Targets:"
	@echo "  all        - build $(NAME)"
	@echo "  clean      - remove objects"
	@echo "  fclean     - remove objects and binary"
	@echo "  re         - rebuild from scratch"
	@echo "  debug      - rebuild with -g3 -O0"
	@echo "  sanitize   - rebuild with AddressSanitizer"
	@echo "  run ARGS=  - run with arguments"

-include $(DEPS)

.PHONY: all clean fclean re checker
