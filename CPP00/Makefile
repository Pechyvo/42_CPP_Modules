all: 
	make -j$(nproc) -C ex00 
	make -j$(nproc) -C ex01 
	make -j$(nproc) -C ex02

clean:
	@make -C ex00 clean > /dev/null
	@make -C ex01 clean > /dev/null
	@make -C ex02 clean > /dev/null
	@echo "Cleaning up..."

fclean:
	@make -C ex00 fclean > /dev/null
	@make -C ex01 fclean > /dev/null
	@make -C ex02 fclean > /dev/null
	@echo "FCleaning up..."

d: fclean
	make -j$(nproc) -C ex00 DEBUG=1
	make -j$(nproc) -C ex01 DEBUG=1
	make -j$(nproc) -C ex02 DEBUG=1

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