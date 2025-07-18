all: 
	make -j$(nproc) -C ex00 
	make -j$(nproc) -C ex01 
	make -j$(nproc) -C ex02
	make -j$(nproc) -C ex03
	make -j$(nproc) -C ex04
	make -j$(nproc) -C ex05
	make -j$(nproc) -C ex06

clean:
	@make -C ex00 clean > /dev/null
	@make -C ex01 clean > /dev/null
	@make -C ex02 clean > /dev/null
	@make -C ex03 clean > /dev/null
	@make -C ex04 clean > /dev/null
	@make -C ex05 clean > /dev/null
	@make -C ex06 clean > /dev/null
	@echo "$(BOLD)$(YELLOW)Cleaning up...$(RESET)"

fclean:
	@make -C ex00 fclean > /dev/null
	@make -C ex01 fclean > /dev/null
	@make -C ex02 fclean > /dev/null
	@make -C ex03 fclean > /dev/null
	@make -C ex04 fclean > /dev/null
	@make -C ex05 fclean > /dev/null
	@make -C ex06 fclean > /dev/null
	@echo "$(BOLD)$(YELLOW)FCleaning up...$(RESET)"

#Debugging
d: fclean
	make -j$(nproc) -C ex00 DEBUG=1
	make -j$(nproc) -C ex01 DEBUG=1
	make -j$(nproc) -C ex02 DEBUG=1
	make -j$(nproc) -C ex03 DEBUG=1
	make -j$(nproc) -C ex04 DEBUG=1
	make -j$(nproc) -C ex05 DEBUG=1
	make -j$(nproc) -C ex06 DEBUG=1

#Run Exercises

# Variable to control valgrind usage
VALGRIND = valgrind --leak-check=full

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

#all - compile once, run all with valgrind
run: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (zombie):$(RESET)"
	$(VALGRIND) ./zombie
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (horde):$(RESET)"
	$(VALGRIND) ./horde
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (brain):$(RESET)"
	$(VALGRIND) ./brain
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex03 (weapon):$(RESET)"
	$(VALGRIND) ./weapon
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex04 (sed):$(RESET)"
	@echo "$(CYAN)  Test 1: No arguments (usage)$(RESET)"
	-$(VALGRIND) ./sed
	@echo
	@echo "$(CYAN)  Test 2: Empty string replacement$(RESET)"
	-$(VALGRIND) ./sed ex04/file "" you
	@echo
	@echo "$(CYAN)  Test 3: Normal replacement$(RESET)"
	$(VALGRIND) ./sed ex04/file me you
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex05 (harl):$(RESET)"
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-$(VALGRIND) ./harl
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-$(VALGRIND) ./harl DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-$(VALGRIND) ./harl RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: DEBUG level$(RESET)"
	$(VALGRIND) ./harl DEBUG
	@echo
	@echo "$(CYAN)  Test 5: INFO level$(RESET)"
	$(VALGRIND) ./harl INFO
	@echo
	@echo "$(CYAN)  Test 6: WARNING level$(RESET)"
	$(VALGRIND) ./harl WARNING
	@echo
	@echo "$(CYAN)  Test 7: ERROR level$(RESET)"
	$(VALGRIND) ./harl ERROR
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex06 (harlFilter):$(RESET)"
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-$(VALGRIND) ./harlFilter
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-$(VALGRIND) ./harlFilter DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-$(VALGRIND) ./harlFilter RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: DEBUG level$(RESET)"
	$(VALGRIND) ./harlFilter DEBUG
	@echo
	@echo "$(CYAN)  Test 5: INFO level$(RESET)"
	$(VALGRIND) ./harlFilter INFO
	@echo
	@echo "$(CYAN)  Test 6: WARNING level$(RESET)"
	$(VALGRIND) ./harlFilter WARNING
	@echo
	@echo "$(CYAN)  Test 7: ERROR level$(RESET)"
	$(VALGRIND) ./harlFilter ERROR

#all - compile once, run all without valgrind
runfast: fclean all
	@echo "$(BOLD)$(YELLOW)Running ex00 (zombie):$(RESET)"
	./zombie
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (horde):$(RESET)"
	./horde
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (brain):$(RESET)"
	./brain
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex03 (weapon):$(RESET)"
	./weapon
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex04 (sed):$(RESET)"
	@echo "$(CYAN)  Test 1: No arguments (usage)$(RESET)"
	-./sed
	@echo
	@echo "$(CYAN)  Test 2: Empty string replacement$(RESET)"
	-./sed ex04/file "" you
	@echo
	@echo "$(CYAN)  Test 3: Normal replacement$(RESET)"
	./sed ex04/file me you
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex05 (harl):$(RESET)"
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-./harl
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-./harl DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-./harl RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: DEBUG level$(RESET)"
	./harl DEBUG
	@echo
	@echo "$(CYAN)  Test 5: INFO level$(RESET)"
	./harl INFO
	@echo
	@echo "$(CYAN)  Test 6: WARNING level$(RESET)"
	./harl WARNING
	@echo
	@echo "$(CYAN)  Test 7: ERROR level$(RESET)"
	./harl ERROR
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex06 (harlFilter):$(RESET)"
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-./harlFilter
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-./harlFilter DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-./harlFilter RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: DEBUG level$(RESET)"
	./harlFilter DEBUG
	@echo
	@echo "$(CYAN)  Test 5: INFO level$(RESET)"
	./harlFilter INFO
	@echo
	@echo "$(CYAN)  Test 6: WARNING level$(RESET)"
	./harlFilter WARNING
	@echo
	@echo "$(CYAN)  Test 7: ERROR level$(RESET)"
	./harlFilter ERROR

#all - compile once in debug mode, run all with valgrind
rund: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (zombie) - DEBUG:$(RESET)"
	$(VALGRIND) ./zombie
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (horde) - DEBUG:$(RESET)"
	$(VALGRIND) ./horde
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (brain) - DEBUG:$(RESET)"
	$(VALGRIND) ./brain
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex03 (weapon) - DEBUG:$(RESET)"
	$(VALGRIND) ./weapon
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex04 (sed) - DEBUG:$(RESET)"
	@echo "$(CYAN)  Test 1: No arguments (usage)$(RESET)"
	-$(VALGRIND) ./sed
	@echo
	@echo "$(CYAN)  Test 2: Empty string replacement$(RESET)"
	-$(VALGRIND) ./sed ex04/file "" you
	@echo
	@echo "$(CYAN)  Test 3: Normal replacement$(RESET)"
	$(VALGRIND) ./sed ex04/file me you
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex05 (harl) - DEBUG:$(RESET)"
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-$(VALGRIND) ./harl
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-$(VALGRIND) ./harl DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-$(VALGRIND) ./harl RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: Random level (DEBUG mode)$(RESET)"
	$(VALGRIND) ./harl TEST
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex06 (harlFilter) - DEBUG:$(RESET)"
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-$(VALGRIND) ./harlFilter
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-$(VALGRIND) ./harlFilter DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-$(VALGRIND) ./harlFilter RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: Random level (DEBUG mode)$(RESET)"
	$(VALGRIND) ./harlFilter TEST

#all - compile once in debug mode, run all without valgrind
rundfast: fclean d
	@echo "$(BOLD)$(YELLOW)Running ex00 (zombie) - DEBUG:$(RESET)"
	./zombie
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex01 (horde) - DEBUG:$(RESET)"
	./horde
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex02 (brain) - DEBUG:$(RESET)"
	./brain
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex03 (weapon) - DEBUG:$(RESET)"
	./weapon
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex04 (sed) - DEBUG:$(RESET)"
	@echo "$(CYAN)  Test 1: No arguments (usage)$(RESET)"
	-./sed
	@echo
	@echo "$(CYAN)  Test 2: Empty string replacement$(RESET)"
	-./sed ex04/file "" you
	@echo
	@echo "$(CYAN)  Test 3: Normal replacement$(RESET)"
	./sed ex04/file me you
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex05 (harl) - DEBUG:$(RESET)"
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-./harl
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-./harl DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-./harl RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: Random level (DEBUG mode)$(RESET)"
	./harl TEST
	@echo
	@echo "$(BOLD)$(YELLOW)Running ex06 (harlFilter) - DEBUG:$(RESET)"
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-./harlFilter
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-./harlFilter DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-./harlFilter RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: Random level (DEBUG mode)$(RESET)"
	./harlFilter TEST

#Individual exercises (compile and run with valgrind)
#ex00
zmb: fclean all
	$(VALGRIND) ./zombie

zmbd: fclean d
	$(VALGRIND) ./zombie

#ex01
hrd: fclean all
	$(VALGRIND)  ./horde

hrdd: fclean d
	$(VALGRIND)  ./horde

#ex02
brn: fclean all
	$(VALGRIND)  ./brain

#ex03
wpn: fclean all
	$(VALGRIND)  ./weapon

wpnd: fclean d
	$(VALGRIND)  ./weapon

#ex04
sd: fclean all
	@echo "$(CYAN)  Test 1: No arguments (usage)$(RESET)"
	-$(VALGRIND)  ./sed
	@echo
	@echo "$(CYAN)  Test 2: Empty string replacement$(RESET)"
	-$(VALGRIND)  ./sed ex04/file "" you
	@echo
	@echo "$(CYAN)  Test 3: Normal replacement$(RESET)"
	$(VALGRIND)  ./sed ex04/file me you

#ex05
hrl: fclean all
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-$(VALGRIND) ./harl
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-$(VALGRIND) ./harl DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-$(VALGRIND) ./harl RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: DEBUG level$(RESET)"
	$(VALGRIND) ./harl DEBUG
	@echo
	@echo "$(CYAN)  Test 5: INFO level$(RESET)"
	$(VALGRIND) ./harl INFO
	@echo
	@echo "$(CYAN)  Test 6: WARNING level$(RESET)"
	$(VALGRIND) ./harl WARNING
	@echo
	@echo "$(CYAN)  Test 7: ERROR level$(RESET)"
	$(VALGRIND) ./harl ERROR

hrld: fclean d
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-$(VALGRIND) ./harl
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-$(VALGRIND) ./harl DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-$(VALGRIND) ./harl RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: Random level (DEBUG mode)$(RESET)"
	$(VALGRIND) ./harl TEST

#ex06
flt: fclean all
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-$(VALGRIND) ./harlFilter
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-$(VALGRIND) ./harlFilter DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-$(VALGRIND) ./harlFilter RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: DEBUG level$(RESET)"
	$(VALGRIND) ./harlFilter DEBUG
	@echo
	@echo "$(CYAN)  Test 5: INFO level$(RESET)"
	$(VALGRIND) ./harlFilter INFO
	@echo
	@echo "$(CYAN)  Test 6: WARNING level$(RESET)"
	$(VALGRIND) ./harlFilter WARNING
	@echo
	@echo "$(CYAN)  Test 7: ERROR level$(RESET)"
	$(VALGRIND) ./harlFilter ERROR

fltd: fclean d
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-$(VALGRIND) ./harlFilter
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-$(VALGRIND) ./harlFilter DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-$(VALGRIND) ./harlFilter RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: Random level (DEBUG mode)$(RESET)"
	$(VALGRIND) ./harlFilter TEST

#Individual exercises (just run, no compilation)
#ex00
zmbr:
	$(VALGRIND) ./zombie

#ex01
hrdr:
	$(VALGRIND)  ./horde

#ex02
brnr:
	$(VALGRIND)  ./brain

#ex03
wpnr:
	$(VALGRIND)  ./weapon

#ex04
sdr:
	@echo "$(CYAN)  Test 1: No arguments (usage)$(RESET)"
	-$(VALGRIND)  ./sed
	@echo
	@echo "$(CYAN)  Test 2: Empty string replacement$(RESET)"
	-$(VALGRIND)  ./sed ex04/file "" you
	@echo
	@echo "$(CYAN)  Test 3: Normal replacement$(RESET)"
	$(VALGRIND)  ./sed ex04/file me you

#ex05
hrlr:
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-$(VALGRIND) ./harl
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-$(VALGRIND) ./harl DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-$(VALGRIND) ./harl RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: DEBUG level$(RESET)"
	$(VALGRIND) ./harl DEBUG
	@echo
	@echo "$(CYAN)  Test 5: INFO level$(RESET)"
	$(VALGRIND) ./harl INFO
	@echo
	@echo "$(CYAN)  Test 6: WARNING level$(RESET)"
	$(VALGRIND) ./harl WARNING
	@echo
	@echo "$(CYAN)  Test 7: ERROR level$(RESET)"
	$(VALGRIND) ./harl ERROR

#ex06
fltr:
	@echo "$(CYAN)  Test 1: No arguments$(RESET)"
	-$(VALGRIND) ./harlFilter
	@echo
	@echo "$(CYAN)  Test 2: More than 1 argument$(RESET)"
	-$(VALGRIND) ./harlFilter DEBUG INFO
	@echo
	@echo "$(CYAN)  Test 3: Random argument$(RESET)"
	-$(VALGRIND) ./harlFilter RANDOM_ARG
	@echo
	@echo "$(CYAN)  Test 4: DEBUG level$(RESET)"
	$(VALGRIND) ./harlFilter DEBUG
	@echo
	@echo "$(CYAN)  Test 5: INFO level$(RESET)"
	$(VALGRIND) ./harlFilter INFO
	@echo
	@echo "$(CYAN)  Test 6: WARNING level$(RESET)"
	$(VALGRIND) ./harlFilter WARNING
	@echo
	@echo "$(CYAN)  Test 7: ERROR level$(RESET)"
	$(VALGRIND) ./harlFilter ERROR

re: fclean all

.PHONY: all clean fclean re