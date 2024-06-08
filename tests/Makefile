
NAME        = so_long
SRCDIR      = ../submit
SRCS        = $(shell find $(SRCDIR) -not -name "main.c" -name "*.c" -type f | xargs) test_leaks.c main.c
OBJS        = $(SRCS:%.c=%.o)
DEPENDS     = $(OBJS:.o=.d)
LIBFT		= libft
CFLAGS      = -Wall -Wextra -Werror -MMD -MP -I $(SRCDIR)/libft -I $(SRCDIR) -g -O0
LOADLIBES	= -L $(SRCDIR)/libft
LDLIBS      = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%_test: $(OBJS) %_test.o
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	find . -name "*.o" -delete
	find . -name "*.d" -delete
	rm -f $(OBJS) $(DEPENDS)

fclean: clean
	find . -not -name "*.*" -not -name "Makefile" -type f -delete

re: fclean all

-include .development.mk

show:
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LDLIBS		: $(LDLIBS)\n"
	@printf "SRCS		:\n	$(SRCS)\n"
	@printf "OBJS		:\n	$(OBJS)\n"

.PHONY: all

-include $(DEPENDS)
