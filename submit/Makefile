
NAME        = so_long
SRCDIR      = .
SRCS        = $(shell find $(SRCDIR) -name "*.c" -type f -not -path "*/libft/*.c" | xargs)
OBJS        = $(SRCS:%.c=%.o)
DEPENDS     = $(OBJS:.o=.d)
LIBFT		= libft
CFLAGS      = -Wall -Wextra -Werror -MMD -MP -I libft
LOADLIBES	= -L libft
ifeq ($(shell uname),Linux)
	CFLAGS += -I /usr/include
	LDLIBS  = -lmlx_Linux -lft -lXext -lX11 -lm
else
	LDLIBS  = -lmlx -lmlx -lft -framework OpenGL -framework AppKit
endif

all: $(NAME)

-include $(DEPENDS)

$(NAME): $(LIBFT) $(OBJS)
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

debug: CFLAGS += -g -O0 -fsanitize=leak -fstack-protector-all -ftrapv -fanalyzer
debug: re

.PHONY: all

### installing

$(LIBFT):
	rm -rf tmp_Libft
	git clone --progress --depth 1 git@github.com:PalmNeko/Libft.git tmp_Libft
	cp -r tmp_Libft/submit $(LIBFT)
	rm -rf tmp_Libft
	make -C $(LIBFT)
