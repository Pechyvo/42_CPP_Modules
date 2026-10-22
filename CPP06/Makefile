# Color definitions
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
RESET = \033[0m

# Text formatting
BOLD = \033[1m
DIM = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m
BLINK = \033[5m
REVERSE = \033[7m
STRIKETHROUGH = \033[9m

# Variable to control valgrind usage
VALGRIND = valgrind --leak-check=full

all:
	$(MAKE) -C ex00
	$(MAKE) -C ex01
	$(MAKE) -C ex02

clean:
	@$(MAKE) -C ex00 clean > /dev/null
	@$(MAKE) -C ex01 clean > /dev/null
	@$(MAKE) -C ex02 clean > /dev/null
	@echo "$(BOLD)$(YELLOW)Cleaning up...$(RESET)"

fclean:
	@$(MAKE) -C ex00 fclean > /dev/null
	@$(MAKE) -C ex01 fclean > /dev/null
	@$(MAKE) -C ex02 fclean > /dev/null
	@rm -rf *_shrubbery
	@echo "$(BOLD)$(YELLOW)FCleaning up...$(RESET)"

# Debugging
d: fclean
	$(MAKE) -C ex00 DEBUG=1
	$(MAKE) -C ex01 DEBUG=1
	$(MAKE) -C ex02 DEBUG=1

# Run Exercises

# all - compile once, run all with valgrind
run: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (ScalarConverter):$(RESET)"
	$(VALGRIND) ./conv
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Serialization):$(RESET)"
	$(VALGRIND) ./ser
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Type Identification):$(RESET)"
	$(VALGRIND) ./type

# all - compile once, run all without valgrind
runfast: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (ScalarConverter):$(RESET)"
	./conv
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Serialization):$(RESET)"
	./ser
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Type Identification):$(RESET)"
	./type

# all - compile once in debug mode, run all with valgrind
rund: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (ScalarConverter) - DEBUG:$(RESET)"
	$(VALGRIND) ./conv
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Serialization) - DEBUG:$(RESET)"
	$(VALGRIND) ./ser
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Type Identification) - DEBUG:$(RESET)"
	$(VALGRIND) ./type

# all - compile once in debug mode, run all without valgrind
rundfast: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (ScalarConverter) - DEBUG:$(RESET)"
	./conv
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Serialization) - DEBUG:$(RESET)"
	./ser
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Type Identification) - DEBUG:$(RESET)"
	./type

# Individual exercises (compile and run with valgrind)
# ex00
conv: fclean
	$(MAKE) -C ex00
	$(VALGRIND) ./conv

convd: fclean
	$(MAKE) -C ex00 DEBUG=1
	$(VALGRIND) ./conv

# ex01
ser: fclean
	$(MAKE) -C ex01
	$(VALGRIND) ./ser

serd: fclean
	$(MAKE) -C ex01 DEBUG=1
	$(VALGRIND) ./ser

# ex02
type: fclean
	$(MAKE) -C ex02
	$(VALGRIND) ./type

typed: fclean
	$(MAKE) -C ex02 DEBUG=1
	$(VALGRIND) ./type

# Individual exercises (just run, no compilation)
# ex00
convr:
	$(VALGRIND) ./conv

# ex01
serr:
	$(VALGRIND) ./ser

# ex02
typer:
	$(VALGRIND) ./type

re: fclean all

.PHONY: all clean fclean re d run runfast rund rundfast conv convd convr ser serd serr type typed typer