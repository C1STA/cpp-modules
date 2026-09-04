EXERCISES := $(sort $(patsubst %/,%,$(dir $(wildcard cpp-*/ex*/Makefile))))

all:
	@set -e; for exercise in $(EXERCISES); do \
		printf 'Building %s\n' "$$exercise"; \
		$(MAKE) --no-print-directory -s -C "$$exercise" >/dev/null; \
	done

clean:
	@set -e; for exercise in $(EXERCISES); do \
		$(MAKE) --no-print-directory -s -C "$$exercise" clean >/dev/null; \
	done

fclean:
	@set -e; for exercise in $(EXERCISES); do \
		$(MAKE) --no-print-directory -s -C "$$exercise" fclean >/dev/null; \
	done

re: fclean all

list:
	@printf '%s\n' $(EXERCISES)

.PHONY: all clean fclean re list
