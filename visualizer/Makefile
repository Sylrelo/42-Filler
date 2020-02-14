NAME	= filler-gui
DESC	= FILLER VISUALIZER
SRCS 	= main.c mlx.utils.c parse.c draw.c map.c infobar.c init.colors.c

OBJ_DIR = ./.objs
SRC_DIR = ./srcs
INC_DIR = -I./mlx -I./includes -I../libft/includes

INC_H	= includes/general.h ../libft/includes/libft.h ../libft/includes/get_next_line.h ../libft/libft.a
INC_LIB = -L../libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit
CFLAGS	:= -Wall -Wextra -Werror
OBJS	:= $(patsubst %.c,$(OBJ_DIR)/%.o, $(SRCS))

ERASE	= \033[2K\r
BLUE	= \033[36m
WHITE	= \033[37m
END		= \033[0m
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m

all: FT_MAKE_LIB $(NAME)

FT_MAKE_LIB:
		@make -C ../libft/
FT_REMAKE_LIB:
		@make re -C ../libft/
		@make re -C ./mlx/

$(NAME): $(OBJS)
		@make -C ./mlx/
		@gcc ${CFLAGS} ${INC_LIB} $^ -o ${NAME}
		@printf "$(ERASE)$(BLUE)--$(END)\n"
		@printf "$(ERASE)-> $(GREEN)$(DESC)$(WHITE): success.$(END)\n"


$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_H)
		@mkdir -p .objs
		@gcc $(CFLAGS) $(INC_DIR) -o $@ -c $<
		@printf "$(ERASE)>> $(BLUE)$(DESC)$(WHITE): $<$(END)"

clean:
		@rm -rf $(OBJS)
		@make clean -C mlx/
		@printf "$(ERASE)>> $(YELLOW)$(DESC)$(WHITE): objects deleted.$(END)\n"

fclean : clean
		@rm -f $(NAME)
		@rm -rf $(OBJ_DIR)
		@make fclean -C ../libft/
		@printf "$(ERASE)>> $(YELLOW)$(DESC)$(WHITE): library deleted.$(END)\n"

re:		fclean all
