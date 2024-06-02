
watch-build:
	@bash .watch-build.sh '-not -name "*.o" -not -name "*.d" -not -name "$(NAME)"'

lint:
	@! norminette | grep -v -E ': OK!$$'

watch-lint:
	@bash .watch-lint.sh '-not -name "*.o" -not -name "*.d" -not -name "$(NAME)"'
