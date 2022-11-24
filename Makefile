CPP=g++ --std=c++11 -Wall

all : Tuile DominoCarre Bouton main
	$(CPP) Tuile.o DominoCarre.o Bouton.o main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app

Bouton : Bouton.o
	$(CPP) -c Bouton.cpp

DominoCarre : DominoCarre.o
	$(CPP) -c DominoCarre.cpp

Tuile : Tuile.o
	$(CPP) -c Tuile.cpp

main : main.o
	$(CPP) -c main.cpp

clean :
	rm *.o *.out sfml-app