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
	@echo "$(BOLD)$(YELLOW)Running ex00 (Easyfind):$(RESET)"
	$(VALGRIND) ./easyfind
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Span):$(RESET)"
	$(VALGRIND) ./span
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Mutant Stack):$(RESET)"
	$(VALGRIND) ./mutant

# all - compile once, run all without valgrind
runfast: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (Easyfind):$(RESET)"
	./easyfind
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Span):$(RESET)"
	./span
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Mutant Stack):$(RESET)"
	./mutant

# all - compile once in debug mode, run all with valgrind
rund: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (Easyfind) - DEBUG:$(RESET)"
	$(VALGRIND) ./easyfind
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Span) - DEBUG:$(RESET)"
	$(VALGRIND) ./span
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Mutant Stack) - DEBUG:$(RESET)"
	$(VALGRIND) ./mutant

# all - compile once in debug mode, run all without valgrind
rundfast: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (Easyfind) - DEBUG:$(RESET)"
	./easyfind
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (Span) - DEBUG:$(RESET)"
	./span
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (Mutant Stack) - DEBUG:$(RESET)"
	./mutant

# Individual exercises (compile and run with valgrind)
# ex00
easyfind: fclean
	make -j$(nproc) -C ex00
	$(VALGRIND) ./easyfind

easyfind_d: fclean
	make -j$(nproc) -C ex00 DEBUG=1
	$(VALGRIND) ./easyfind

# ex01
span: fclean
	make -j$(nproc) -C ex01
	$(VALGRIND) ./span

span_d: fclean
	make -j$(nproc) -C ex01 DEBUG=1
	$(VALGRIND) ./span

# ex02
mutant: fclean
	make -j$(nproc) -C ex02
	$(VALGRIND) ./mutant

mutant_d: fclean
	make -j$(nproc) -C ex02 DEBUG=1
	$(VALGRIND) ./mutant

# Individual exercises (just run, no compilation)
# ex00
easyfind_r:
	$(VALGRIND) ./easyfind

# ex01
span_r:
	$(VALGRIND) ./span

# ex02
mutant_r:
	$(VALGRIND) ./mutant

re: fclean all

.PHONY: all clean fclean re d run runfast rund rundfast easyfind easyfind_d easyfind_r span span_d span_r mutant mutant_d mutant_r