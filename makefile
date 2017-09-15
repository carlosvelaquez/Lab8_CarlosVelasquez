out: Luchador.o Alquimista.o Aprendiz.o DeshacerDano.o DobleAtaque.o DobleExp.o DragonBorn.o Guerrero.o HabilidadEspecial.o HabilidadPasiva.o Invulnerabilidad.o Mago.o Regeneracion.o Lista.o main.o Habilidad.o
	g++ -pthread Luchador.o Alquimista.o Aprendiz.o DeshacerDano.o DobleAtaque.o DobleExp.o DragonBorn.o Guerrero.o HabilidadEspecial.o HabilidadPasiva.o Invulnerabilidad.o Mago.o Regeneracion.o Lista.o main.o Habilidad.o -o out

Luchador.o: Luchador.h Luchador.cpp
	g++ -c -g Luchador.cpp

Alquimista.o: Alquimista.h Alquimista.cpp
	g++ -c -g Alquimista.cpp

Aprendiz.o: Aprendiz.h Aprendiz.cpp
	g++ -c -g Aprendiz.cpp

DeshacerDano.o: DeshacerDano.h DeshacerDano.cpp
	g++ -c -g DeshacerDano.cpp

DobleAtaque.o: DobleAtaque.h DobleAtaque.cpp
	g++ -c -g DobleAtaque.cpp

DobleExp.o: DobleExp.h DobleExp.cpp
	g++ -c -g DobleExp.cpp

DragonBorn.o: DragonBorn.h DragonBorn.cpp
	g++ -c -g DragonBorn.cpp

Guerrero.o: Guerrero.h Guerrero.cpp
	g++ -c -g Guerrero.cpp

HabilidadEspecial.o: HabilidadEspecial.h HabilidadEspecial.cpp
	g++ -c -g HabilidadEspecial.cpp

HabilidadPasiva.o: HabilidadPasiva.h HabilidadPasiva.cpp
	g++ -c -g HabilidadPasiva.cpp

Invulnerabilidad.o: Invulnerabilidad.h Invulnerabilidad.cpp
	g++ -c -g Invulnerabilidad.cpp

Lista.o: Lista.h Lista.cpp
	g++ -c -g Lista.cpp

Mago.o: Mago.h Mago.cpp
	g++ -c -g Mago.cpp

Regeneracion.o: Regeneracion.h Regeneracion.cpp
	g++ -c -g Regeneracion.cpp

main.o: main.cpp
	g++ -c -g main.cpp

Habilidad.o: Habilidad.h Habilidad.cpp
	g++ -c -g Habilidad.cpp

clean:
	rm -rf *.o
