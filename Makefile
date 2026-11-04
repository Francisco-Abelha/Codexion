NAME =  codexion

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

INCLUDES = -Iincludes

SRCS = $(SRC_DIR)/codexion.c \
	   $(SRC_DIR)/parser.c \
	   $(SRC_DIR)/utils.c

OBJ_DIR = objects
SRC_DIR = sources

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32m✓ make successful\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re