
watch:
	@ clear;
	@ make -s lint && make -s; \
	while true; do \
		bash .wait_update.sh '-not -name "*.o" -not -name "*.d" -not -name "$(NAME)"'; \
		clear; \
		make lint && \
			make -s; \
		sleep 1; \
	done

test:
	@clear
	@echo \> ./$(NAME)
	@test -f ./$(NAME) && ./$(NAME) || echo "Error: ./$(NAME)"

test-watch:
	@clear
	@make test
	@while true; do \
		bash .wait_update.sh '-name "$(NAME)"'; \
		make test ; \
	done

lint:
	@! norminette | grep -v -E ': OK!$$'
