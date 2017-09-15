out: Luchador.o DragonBorn.o Lista.o main.o
	g++ Luchador.o DragonBorn.o Lista.o main.o -o out

Luchador.o: Luchador.h Luchador.cpp
	g++ -c -g Luchador.cpp

DragonBorn.o: DragonBorn.h DragonBorn.cpp
	g++ -c -g DragonBorn.cpp

Lista.o: Lista.h Lista.cpp
	g++ -c -g Lista.cpp

main.o: main.cpp
	g++ -c -g main.cpp

clean:
	rm -rf *.o
