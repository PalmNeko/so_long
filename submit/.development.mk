
watch-build:
	@bash .watch-build.sh '-not -name "*.o" -not -name "*.d" -not -name "$(NAME)"'

lint:
	$(CC) $(SRCS) $(CFLAGS) -fsyntax-only $(SRCS)
	@! norminette | grep -v -E ': OK!$$'

watch-lint:
	@bash .watch-lint.sh '-not -name "*.o" -not -name "*.d" -not -name "$(NAME)"'
