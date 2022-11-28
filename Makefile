CPP=g++ --std=c++11 -Wall

all : Tuile DominoCarre Bouton main
	$(CPP) Tuile.o DominoCarre.o gui/Bouton.o main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app

Bouton : gui/Bouton.o
	$(CPP) -c gui/Bouton.cpp

DominoCarre : DominoCarre.o
	$(CPP) -c DominoCarre.cpp

Tuile : Tuile.o
	$(CPP) -c Tuile.cpp

main : main.o
	$(CPP) -c main.cpp

clean :
	rm *.o gui/*.o sfml-app