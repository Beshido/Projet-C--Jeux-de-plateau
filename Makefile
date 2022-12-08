CPP=g++ --std=c++11 -Wall

all : DominoCarre Bouton DominoCarreTuileGUI main
	$(CPP) DominoCarre.o gui/Bouton.o gui/DominoCarreTuileGUI.o main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app

Bouton : gui/Bouton.o
	$(CPP) -c gui/Bouton.cpp

DominoCarreTuileGUI : gui/DominoCarreTuileGUI.o
	$(CPP) -c gui/DominoCarreTuileGUI.cpp

DominoCarre : DominoCarre.o
	$(CPP) -c DominoCarre.cpp

main : main.o
	$(CPP) -c main.cpp

clean :
	rm *.o gui/*.o sfml-app