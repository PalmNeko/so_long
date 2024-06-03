
NAME        = so_long
SRCDIR      = ./
SRCS        = $(shell find $(SRCDIR) -name "*.c" -type f | xargs)
OBJS        = $(SRCS:%.c=%.o)
DEPENDS     = $(OBJS:.o=.d)
CFLAGS      = -Wall -Wextra -Werror -MMD -MP
LDLIBS      = -lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

-include $(DEPENDS)

$(NAME): $(OBJS)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(OBJS) $(DEPENDS)
	rm -rf $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include .development.mk

show:
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LDLIBS		: $(LDLIBS)\n"
	@printf "SRCS		:\n	$(SRCS)\n"
	@printf "OBJS		:\n	$(OBJS)\n"

debug: CFLAGS += -g -O0
debug: re

.PHONY: all
