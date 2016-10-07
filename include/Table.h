#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "FileTable.h"

#define TAM  4
#define FICH 16
#define UP   1
#define DOWN 2
#define LEFT 3
#define RIGH 4

using namespace std;

class Table
{
public:
	Table(void);
	~Table(void);
	void origin();
protected:
        time_t t;
        FileTable table[TAM][TAM];
        int valueRadom;
        void printfTable(FileTable table[TAM][TAM]);
        int valuePosRandom(FileTable table[TAM][TAM],int x, int y);
        int numRandom(int limSup, int limInf);
        void exhibitFile(FileTable table[TAM][TAM],int x, int y);
		void initTable(FileTable table[TAM][TAM],int x, int y);
		void travelTableInit();
		void firstTwoFile();
		void fileRandomPlay();
		void dirMov();
		int moveFile(int dir);

		int upTable(FileTable table[TAM][TAM],int x, int y);
		int downTable(FileTable table[TAM][TAM],int x, int y);
		int leftTable(FileTable table[TAM][TAM],int x, int y);
		int rightTable(FileTable table[TAM][TAM],int x, int y);

		int upPossible(FileTable table[TAM][TAM],int x, int y);
		int downPossible(FileTable table[TAM][TAM],int x, int y);
		int leftPossible(FileTable table[TAM][TAM],int x, int y);
		int rightPossible(FileTable table[TAM][TAM],int x, int y);

		int upEat(FileTable table[TAM][TAM],int x, int y);
		int downEat(FileTable table[TAM][TAM],int x, int y);
		int leftEat(FileTable table[TAM][TAM],int x, int y);
		int rightEat(FileTable table[TAM][TAM],int x, int y);

		int upMove();
		int downMove();
		int leftMove();
		int rightMove();

		void upPossibleMove(int &pos);
		void downPossibleMove(int &pos);
		void leftPossibleMove(int &pos);
		void rightPossibleMove(int &pos);

		int upMoveEat();
		int downMoveEat();
		int leftMoveEat();
		int rightMoveEat();

		int upPossibleEat(FileTable table[TAM][TAM],int x, int y);
		int downPossibleEat(FileTable table[TAM][TAM],int x, int y);
		int leftPossibleEat(FileTable table[TAM][TAM],int x, int y);
		int rightPossibleEat(FileTable table[TAM][TAM],int x, int y);

		int upPossibleMoveEat();
		int downPossibleMoveEat();
		int leftPossibleMoveEat();
		int rightPossibleMoveEat();

		int checkGameOver(FileTable table[TAM][TAM]);
private:
    int score;
};

#endif // TABLERO_H
