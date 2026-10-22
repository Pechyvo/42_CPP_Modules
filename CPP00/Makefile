all:
	$(MAKE) -C ex00
	$(MAKE) -C ex01
	$(MAKE) -C ex02

clean:
	@$(MAKE) -C ex00 clean > /dev/null
	@$(MAKE) -C ex01 clean > /dev/null
	@$(MAKE) -C ex02 clean > /dev/null
	@echo "Cleaning up..."

fclean:
	@$(MAKE) -C ex00 fclean > /dev/null
	@$(MAKE) -C ex01 fclean > /dev/null
	@$(MAKE) -C ex02 fclean > /dev/null
	@echo "FCleaning up..."

d: fclean
	$(MAKE) -C ex00 DEBUG=1
	$(MAKE) -C ex01 DEBUG=1
	$(MAKE) -C ex02 DEBUG=1

mp: fclean all
	./megaphone "shhhhh... I think the students are asleep..."
	./megaphone "Damnit " ! " "Sorry students, I thought this thing was off.""
	./megaphone

pb: fclean all
	./phonebook

pbd: fclean d
	./phonebook

ac: fclean all
	./account

re: fclean all

.PHONY: all clean fclean re