NAME = minishell

SRC_DIR = src
OUT_DIR = out
INC_DIR = includes

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

VPATH = $(SRC_DIR):$(SRC_DIR)/wrapper/fdc_wrapper:$(SRC_DIR)/wrapper/gc_wrapper:$(SRC_DIR)/gc:$(SRC_DIR)/error:$(SRC_DIR)/env:$(SRC_DIR)/utils:$(SRC_DIR)/ast:$(SRC_DIR)/builtins:$(SRC_DIR)/execution:$(SRC_DIR)/env:$(SRC_DIR)/fd

SRCS = main.c \
       cleanup.c \
       gc_malloc.c \
       gc_calloc.c \
       gc_realloc.c \
       gc_free.c \
       gc_getcwd.c \
       gc_holder.c \
       gc_add.c \
       gc_remove.c \
       gc_empty.c \
       error_handler.c \
       env.c \
       env_init.c \
       env_empty.c \
       gc_strdup.c \
       gc_strjoin.c \
       gc_split.c \
       gc_substr.c \
       ast_build.c \
       ast_init.c \
       ast_new_node.c \
       ast_parse_pipe.c \
       ast_parse_parentheses.c \
       ast_parse_command.c \
       ast_parse_logical_ops.c \
       ast_empty.c \
       ast_print.c \
       input_transformation.c \
       echo.c \
       execute.c \
       execute_builtin.c \
       execute_external.c \
       execute_pipe.c \
       execute_logical.c \
       execute_utils.c \
       test_execution.c \
       ast_parse_redirection.c \
       gc_split_at.c \
       gc_split_free.c \
       is_redirection.c \
       redir_utils.c \
       fd_holder.c \
       fd_remove.c \
       fd_add.c \
       fd_empty.c \
       fdc_open.c \
       fdc_close.c \
       fdc_dup.c \
       fdc_dup2.c \
       fdc_pipe.c \
       gc_lstclear.c \
       gc_lstnew.c \
       gc_lstremove.c \
       gc_lstdelone.c \
       handle_redirections.c \
       handle_in_redirections.c \
       handle_out_redirections.c \
       expand_env.c \
       get_env.c

OBJS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)/inc
READLINE_FLAGS = -lreadline -ltermcap

all: $(NAME)

$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

$(LIBFT):
	@echo "Creating libft"
	@make -C $(LIBFT_DIR)

$(NAME): $(OUT_DIR) $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME) project"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)

debug: fclean $(OUT_DIR) $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME) project with debug flags"
	@$(CC) -g -fsanitize=address $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)

docker: fclean $(OUT_DIR) $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME) project with debug flags for docker"
	@$(CC) -g $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)

$(OUT_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Deleting $(NAME) objects"
	@rm -rf $(OUT_DIR)
	@echo "Deleting libft objects"
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Deleting $(NAME) executable"
	@rm -f $(NAME)
	@echo "Deleting libft library"
	@make -C $(LIBFT_DIR) fclean

norm:
	@echo "Norminette for $(NAME):"
	@-norminette $(SRC_DIR) $(LIBFT_DIR) $(INC_DIR) || true

bonus: all

re: fclean all

.PHONY: all clean fclean re norm debug docker bonus
