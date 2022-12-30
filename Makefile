CPP=g++ --std=c++11 -Wall
BIN=bin/

all : $(BIN)Bouton.o $(BIN)DominoCarreTileShape.o $(BIN)DominoCarrePlateauShape.o $(BIN)TraxPlateauShape.o $(BIN)TraxTileShape.o $(BIN)DominoCarreScreen.o $(BIN)MenuPrincipal.o $(BIN)TraxScreen.o $(BIN)Assets.o $(BIN)DominoCarre.o $(BIN)DominoCarreTuile.o $(BIN)Trax.o $(BIN)TraxTile.o $(BIN)main.o
	$(CPP) $(BIN)Bouton.o $(BIN)DominoCarreTileShape.o $(BIN)DominoCarrePlateauShape.o $(BIN)TraxPlateauShape.o $(BIN)TraxTileShape.o $(BIN)MenuPrincipal.o $(BIN)TraxScreen.o $(BIN)Assets.o $(BIN)DominoCarreScreen.o $(BIN)DominoCarre.o $(BIN)DominoCarreTuile.o $(BIN)Trax.o $(BIN)TraxTile.o $(BIN)main.o -o $(BIN)sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./$(BIN)sfml-app

$(BIN)Bouton.o : gui/drawable/Bouton.cpp
	$(CPP) -c gui/drawable/Bouton.cpp -o $(BIN)Bouton.o

$(BIN)DominoCarreTileShape.o : gui/drawable/DominoCarreTileShape.cpp
	$(CPP) -c gui/drawable/DominoCarreTileShape.cpp -o $(BIN)DominoCarreTileShape.o

$(BIN)DominoCarrePlateauShape.o : gui/drawable/DominoCarrePlateauShape.cpp
	$(CPP) -c gui/drawable/DominoCarrePlateauShape.cpp -o $(BIN)DominoCarrePlateauShape.o

$(BIN)TraxPlateauShape.o : gui/drawable/TraxPlateauShape.cpp
	$(CPP) -c gui/drawable/TraxPlateauShape.cpp -o $(BIN)TraxPlateauShape.o

$(BIN)TraxTileShape.o : gui/drawable/TraxTileShape.cpp
	$(CPP) -c gui/drawable/TraxTileShape.cpp -o $(BIN)TraxTileShape.o

$(BIN)DominoCarreScreen.o : gui/screens/DominoCarreScreen.cpp
	$(CPP) -c gui/screens/DominoCarreScreen.cpp -o $(BIN)DominoCarreScreen.o

$(BIN)MenuPrincipal.o : gui/screens/MenuPrincipal.cpp
	$(CPP) -c gui/screens/MenuPrincipal.cpp -o $(BIN)MenuPrincipal.o

$(BIN)TraxScreen.o : gui/screens/TraxScreen.cpp
	$(CPP) -c gui/screens/TraxScreen.cpp -o $(BIN)TraxScreen.o

$(BIN)Assets.o : gui/Assets.cpp
	$(CPP) -c gui/Assets.cpp -o $(BIN)Assets.o

$(BIN)DominoCarre.o : logic/DominoCarre.cpp
	$(CPP) -c logic/DominoCarre.cpp -o $(BIN)DominoCarre.o

$(BIN)DominoCarreTuile.o : logic/DominoCarreTuile.cpp
	$(CPP) -c logic/DominoCarreTuile.cpp -o $(BIN)DominoCarreTuile.o

$(BIN)Trax.o : logic/Trax.cpp
	$(CPP) -c logic/Trax.cpp -o $(BIN)Trax.o

$(BIN)TraxTile.o : logic/TraxTile.cpp
	$(CPP) -c logic/TraxTile.cpp -o $(BIN)TraxTile.o

$(BIN)main.o : main.cpp
	$(CPP) -c main.cpp -o $(BIN)main.o

clean :
	$(RM) $(BIN)*.o $(BIN)sfml-app