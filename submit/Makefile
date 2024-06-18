
NAME        = so_long
SRCDIR      = .
SRCS        = $(shell find $(SRCDIR) -name "*.c" -type f -not -path "*/libft/*.c" -not -path "*/minilibx/*.c" | xargs)
OBJS        = $(SRCS:%.c=%.o)
DEPENDS     = $(OBJS:.o=.d)
LIBFT		= libft
CFLAGS      = -Wall -Wextra -Werror -MMD -MP -I libft -O3
LOADLIBES	= -L libft -L minilibx
ifeq ($(shell uname),Linux)
	CFLAGS += -isystem minilibx
	LDLIBS  = -lmlx_Linux -lft -lXext -lX11 -lm
else
	LDLIBS  = -lmlx -lmlx -lft -framework OpenGL -framework AppKit
endif

all: $(NAME)

-include $(DEPENDS)

$(NAME): minilibx $(LIBFT) $(OBJS)
	$(LINK.o) $(OBJS) $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(OBJS) $(DEPENDS)
	rm -rf $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: CFLAGS += -D BONUS
bonus: $(LIBFT) $(OBJS)
	$(LINK.o) $(OBJS) $(LOADLIBES) $(LDLIBS) -o $@

-include .development.mk

show:
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LDLIBS		: $(LDLIBS)\n"
	@printf "SRCS		:\n	$(SRCS)\n"
	@printf "OBJS		:\n	$(OBJS)\n"

debug: CFLAGS += -g -O0 -fsanitize=leak
debug: re

minilibx:
	git clone https://github.com/42Paris/minilibx-linux.git $@
	cd $@ && \
	make

.PHONY: all

### installing

$(LIBFT):
	rm -rf tmp_Libft
	git clone --progress --depth 1 git@github.com:PalmNeko/Libft.git tmp_Libft
	cp -r tmp_Libft/submit $(LIBFT)
	rm -rf tmp_Libft
	make -C $(LIBFT)
