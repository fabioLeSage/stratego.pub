all : case.o plateau.o piece.o joueur.o coord.o main.o
	      g++ -g case.o plateau.o piece.o joueur.o coord.o main.o -o main.exe
	      clang++ case.o plateau.o piece.o joueur.o coord.o main.o - main.exe

case.o : Case.cpp Case.h
	g++ -c -Wall -Wfatal-errors -ansi Case.cpp -o case.o

plateau.o : Plateau.cpp Plateau.h
	g++ -c -Wall -Wfatal-errors -ansi Plateau.cpp -o plateau.o

piece.o : Piece.cpp Piece.h
	g++ -c -Wall -Wfatal-errors -ansi Piece.cpp -o piece.o

joueur.o : Joueur.cpp Joueur.h
	g++ -c -Wall -Wfatal-errors -ansi Joueur.cpp -o joueur.o

coord.o : Coord.cpp Coord.h
	g++ -c -Wall -Wfatal-errors -ansi Coord.cpp -o coord.o

main.o : main.cpp Piece.cpp Joueur.cpp Case.cpp Coord.cpp Plateau.cpp 
	g++ -c -Wall -Wfatal-errors -ansi main.cpp -o main.o

Clean :
	rm *.o:w

