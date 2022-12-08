CPP=g++ --std=c++11 -Wall

all : Bouton DominoCarreTuileGUI DominoCarreGUI MenuPrincipal DominoCarre main
	$(CPP) gui/drawable/Bouton.o gui/drawable/DominoCarreTuileGUI.o gui/screens/MenuPrincipal.o gui/screens/DominoCarreGUI.o DominoCarre.o main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app

Bouton : gui/drawable/Bouton.o
	$(CPP) -c gui/drawable/Bouton.cpp

DominoCarreTuileGUI : gui/drawable/DominoCarreTuileGUI.o
	$(CPP) -c gui/drawable/DominoCarreTuileGUI.cpp

DominoCarreGUI : gui/screens/DominoCarreGUI.o
	$(CPP) -c gui/screens/DominoCarreGUI.cpp

MenuPrincipal : gui/screens/MenuPrincipal.o
	$(CPP) -c gui/screens/MenuPrincipal.cpp

DominoCarre : DominoCarre.o
	$(CPP) -c DominoCarre.cpp

main : main.o
	$(CPP) -c main.cpp

clean :
	rm *.o gui/drawable/*.o gui/screens/*.o sfml-app