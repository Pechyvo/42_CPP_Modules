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
	make -j$(nproc) -C ex00
	make -j$(nproc) -C ex01 
	make -j$(nproc) -C ex02

clean:
	@make -C ex00 clean > /dev/null
	@make -C ex01 clean > /dev/null
	@make -C ex02 clean > /dev/null
	@echo "$(BOLD)$(YELLOW)Cleaning up...$(RESET)"

fclean:
	@make -C ex00 fclean > /dev/null
	@make -C ex01 fclean > /dev/null
	@make -C ex02 fclean > /dev/null
	@rm -rf *_shrubbery
	@echo "$(BOLD)$(YELLOW)FCleaning up...$(RESET)"

# Debugging
d: fclean
	make -j$(nproc) -C ex00 DEBUG=1
	make -j$(nproc) -C ex01 DEBUG=1
	make -j$(nproc) -C ex02 DEBUG=1

# Run Exercises

# all - compile once, run all with valgrind
run: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (Function Templates):$(RESET)"
	$(VALGRIND) ./template
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Iter):$(RESET)"
	$(VALGRIND) ./iter
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Array):$(RESET)"
	$(VALGRIND) ./array

# all - compile once, run all without valgrind
runfast: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (Function Templates):$(RESET)"
	./template
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Iter):$(RESET)"
	./iter
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Array):$(RESET)"
	./array

# all - compile once in debug mode, run all with valgrind
rund: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (Function Templates) - DEBUG:$(RESET)"
	$(VALGRIND) ./template
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Iter) - DEBUG:$(RESET)"
	$(VALGRIND) ./iter
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Array) - DEBUG:$(RESET)"
	$(VALGRIND) ./array

# all - compile once in debug mode, run all without valgrind
rundfast: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (Function Templates) - DEBUG:$(RESET)"
	./template
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Iter) - DEBUG:$(RESET)"
	./iter
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Array) - DEBUG:$(RESET)"
	./array

# Individual exercises (compile and run with valgrind)
# ex00
template: fclean
	make -j$(nproc) -C ex00
	$(VALGRIND) ./template

templated: fclean
	make -j$(nproc) -C ex00 DEBUG=1
	$(VALGRIND) ./template

# ex01
iter: fclean
	make -j$(nproc) -C ex01
	$(VALGRIND) ./iter

iterd: fclean
	make -j$(nproc) -C ex01 DEBUG=1
	$(VALGRIND) ./iter

# ex02
array: fclean
	make -j$(nproc) -C ex02
	$(VALGRIND) ./array

arrayd: fclean
	make -j$(nproc) -C ex02 DEBUG=1
	$(VALGRIND) ./array

# Individual exercises (just run, no compilation)
# ex00
templater:
	$(VALGRIND) ./template

# ex01
iterr:
	$(VALGRIND) ./iter

# ex02
arrayr:
	$(VALGRIND) ./array

re: fclean all

.PHONY: all clean fclean re d run runfast rund rundfast template templated templater iter iterd iterr array arrayd arrayr