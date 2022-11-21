CPP=g++ --std=c++11 -Wall

all : Tuile DominoCarre main
	$(CPP) Tuile.o DominoCarre.o main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app

DominoCarre : DominoCarre.o
	$(CPP) -c DominoCarre.cpp

Tuile : Tuile.o
	$(CPP) -c Tuile.cpp

main : main.o
	$(CPP) -c main.cpp
	

clean :
	rm *.o sfml-app