CPP=g++ --std=c++11 -Wall

all : Bouton DominoCarreGUI DominoCarreTuileGUI DominoCarreScreen MenuPrincipal DominoCarre main
	$(CPP) gui/drawable/Bouton.o gui/drawable/DominoCarreGUI.o gui/drawable/DominoCarreTuileGUI.o gui/screens/MenuPrincipal.o gui/screens/DominoCarreScreen.o DominoCarre.o main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app

Bouton : gui/drawable/Bouton.o
	$(CPP) -c gui/drawable/Bouton.cpp

DominoCarreGUI : gui/drawable/DominoCarreGUI.o
	$(CPP) -c gui/drawable/DominoCarreGUI.cpp

DominoCarreTuileGUI : gui/drawable/DominoCarreTuileGUI.o
	$(CPP) -c gui/drawable/DominoCarreTuileGUI.cpp

DominoCarreScreen : gui/screens/DominoCarreScreen.o
	$(CPP) -c gui/screens/DominoCarreScreen.cpp

MenuPrincipal : gui/screens/MenuPrincipal.o
	$(CPP) -c gui/screens/MenuPrincipal.cpp

DominoCarre : DominoCarre.o
	$(CPP) -c DominoCarre.cpp

main : main.o
	$(CPP) -c main.cpp

clean :
	rm *.o gui/drawable/*.o gui/screens/*.o sfml-app