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
	@echo "$(BOLD)$(YELLOW)Running ex00 (Bitcoin Exchange):$(RESET)"
	$(VALGRIND) ./btc
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (RPN):$(RESET)"
	$(VALGRIND) ./RPN
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (PmergeMe):$(RESET)"
	$(VALGRIND) ./PmergeMe

# all - compile once, run all without valgrind
runfast: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (Bitcoin Exchange):$(RESET)"
	./btc
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (RPN):$(RESET)"
	./RPN
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (PmergeMe):$(RESET)"
	./PmergeMe

# all - compile once in debug mode, run all with valgrind
rund: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (Bitcoin Exchange) - DEBUG:$(RESET)"
	$(VALGRIND) ./btc
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (RPN) - DEBUG:$(RESET)"
	$(VALGRIND) ./RPN
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (PmergeMe) - DEBUG:$(RESET)"
	$(VALGRIND) ./PmergeMe

# all - compile once in debug mode, run all without valgrind
rundfast: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (Bitcoin Exchange) - DEBUG:$(RESET)"
	./btc
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (RPN) - DEBUG:$(RESET)"
	./RPN
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (PmergeMe) - DEBUG:$(RESET)"
	./PmergeMe

# Individual exercises (compile and run with valgrind)
# ex00
btc: fclean
	make -j$(nproc) -C ex00
	$(VALGRIND) ./btc

btc_d: fclean
	make -j$(nproc) -C ex00 DEBUG=1
	$(VALGRIND) ./btc

# ex01
rpn: fclean
	make -j$(nproc) -C ex01
	$(VALGRIND) ./RPN

rpn_d: fclean
	make -j$(nproc) -C ex01 DEBUG=1
	$(VALGRIND) ./RPN

# ex02
pmerge: fclean
	make -j$(nproc) -C ex02
	$(VALGRIND) ./PmergeMe

pmerge_d: fclean
	make -j$(nproc) -C ex02 DEBUG=1
	$(VALGRIND) ./PmergeMe

# Individual exercises (just run, no compilation)
# ex00
btc_r:
	$(VALGRIND) ./btc

# ex01
rpn_r:
	$(VALGRIND) ./RPN

# ex02
pmerge_r:
	$(VALGRIND) ./PmergeMe

re: fclean all

.PHONY: all clean fclean re d run runfast rund rundfast btc btc_d btc_r rpn rpn_d rpn_r pmerge pmerge_d pmerge_r