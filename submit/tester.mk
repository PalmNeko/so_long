
NAME        = so_long_test
SRCDIR      = .
SRCS        = $(shell find $(SRCDIR) -name "*.c" -type f -not -path "*/libft/*.c" -not -path "*/minilibx/*.c" -not -path "*/cident/*" | xargs)
OBJS        = $(SRCS:%.c=%.o)
DEPS 	    = $(OBJS:.o=.d)
LIBFT		= libft
CIDENT		= cident
CFLAGS      = -Wall -Wextra -Werror -MMD -MP -I libft -Icident -I.test -O3 -g -O0 -fsanitize=leak
LDFLAGS		= -fsanitize=leak -L libft -L minilibx -L cident
LDFLAGS		+= \
	-Xlinker --wrap=read \
	-Xlinker --wrap=open \
	-Xlinker --wrap=close \
	-Xlinker --wrap=malloc \
	-Xlinker --wrap=main


ifeq ($(shell uname),Linux)
	CFLAGS += -isystem minilibx
	LDLIBS  = -lmlx_Linux -lft -lXext -lX11 -lm -lcident
else
	LDLIBS  = -lmlx -lmlx -lft -framework OpenGL -framework AppKit
endif

all: $(NAME)

clean:
	rm -f $(OBJS) $(DEPS)
	rm -rf $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

show:
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LDLIBS		: $(LDLIBS)\n"
	@printf "SRCS		:\n	$(SRCS)\n"
	@printf "OBJS		:\n	$(OBJS)\n"

.PHONY: all

$(NAME): minilibx $(CIDENT) $(LIBFT) $(OBJS)
	$(LINK.o) $(OBJS) $(LOADLIBES) $(LDLIBS) -o $@

$(LIBFT):
	rm -rf tmp_Libft
	git clone --progress --depth 1 git@github.com:PalmNeko/Libft.git tmp_Libft
	cp -r tmp_Libft/submit $(LIBFT)
	rm -rf tmp_Libft
	make -C $(LIBFT)

minilibx:
	git clone https://github.com/42Paris/minilibx-linux.git $@
	cd $@ && \
	make

$(CIDENT):
	bash -c "$$(curl https://raw.githubusercontent.com/PalmNeko/cident/main/install.sh)"

-include $(DEPS)
