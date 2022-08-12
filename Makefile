CC = g++
Game.out: main.o menu.o game.o
	g++ -g main.o menu.o game.o -o Game.out
game.o: game.cpp
	g++ -c game.cpp
menu.o: menu.cpp
	g++ -c menu.cpp
main.o: main.cpp
	g++ -c main.cpp



clean:
	rm -rf *.o *.out
