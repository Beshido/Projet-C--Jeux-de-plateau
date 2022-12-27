CPP=g++ --std=c++11 -Wall
BIN=bin/

all : $(BIN)Bouton.o $(BIN)DominoCarreGUI.o $(BIN)DominoCarreJoueurGUI.o $(BIN)DominoCarreTuileGUI.o $(BIN)DominoCarreScreen.o $(BIN)MenuPrincipal.o $(BIN)DominoCarre.o $(BIN)DominoCarreTuile.o $(BIN)main.o
	$(CPP) $(BIN)Bouton.o $(BIN)DominoCarreGUI.o $(BIN)DominoCarreJoueurGUI.o $(BIN)DominoCarreTuileGUI.o $(BIN)MenuPrincipal.o $(BIN)DominoCarreScreen.o $(BIN)DominoCarre.o $(BIN)DominoCarreTuile.o $(BIN)main.o -o $(BIN)sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./$(BIN)sfml-app

$(BIN)Bouton.o : gui/drawable/Bouton.cpp
	$(CPP) -c gui/drawable/Bouton.cpp -o $(BIN)Bouton.o

$(BIN)DominoCarreGUI.o : gui/drawable/DominoCarreGUI.cpp
	$(CPP) -c gui/drawable/DominoCarreGUI.cpp -o $(BIN)DominoCarreGUI.o

$(BIN)DominoCarreJoueurGUI.o : gui/drawable/DominoCarreJoueurGUI.cpp
	$(CPP) -c gui/drawable/DominoCarreJoueurGUI.cpp -o $(BIN)DominoCarreJoueurGUI.o

$(BIN)DominoCarreTuileGUI.o : gui/drawable/DominoCarreTuileGUI.cpp
	$(CPP) -c gui/drawable/DominoCarreTuileGUI.cpp -o $(BIN)DominoCarreTuileGUI.o

$(BIN)DominoCarreScreen.o : gui/screens/DominoCarreScreen.cpp
	$(CPP) -c gui/screens/DominoCarreScreen.cpp -o $(BIN)DominoCarreScreen.o

$(BIN)MenuPrincipal.o : gui/screens/MenuPrincipal.cpp
	$(CPP) -c gui/screens/MenuPrincipal.cpp -o $(BIN)MenuPrincipal.o

$(BIN)DominoCarre.o : logic/DominoCarre.cpp
	$(CPP) -c logic/DominoCarre.cpp -o $(BIN)DominoCarre.o

$(BIN)DominoCarreTuile.o : logic/DominoCarreTuile.cpp
	$(CPP) -c logic/DominoCarreTuile.cpp -o $(BIN)DominoCarreTuile.o

$(BIN)main.o : main.cpp
	$(CPP) -c main.cpp -o $(BIN)main.o

clean :
	rm $(BIN)*.o $(BIN)sfml-app