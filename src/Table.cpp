#include "Table.h"


Table::Table(void)
{
    score = 0;
   srand((unsigned) time(&t));
}


Table::~Table(void)
{
}

void Table::origin(){
    int gameOver = 0;
    travelTableInit();
	printfTable(table);
    firstTwoFile();
	cout<<endl;
    printfTable(table);
    cout<<endl;
	do{
        cout<<"Score: "<<score<<endl;
        dirMov();
        fileRandomPlay();
        printfTable(table);
        gameOver = checkGameOver(table);
        if(!gameOver){
            cout<<endl<<"GAME OVER"<<endl;
        }
        cout<<endl;
	}while(gameOver);
}
void Table::printfTable(FileTable table[TAM][TAM]){
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            exhibitFile(table, i,  j);
            cout<<" ";
        }
        cout<<endl;
    }
}
void Table::exhibitFile(FileTable table[TAM][TAM],int i, int j){
	cout<<table[i][j].getVal();
}

void Table::initTable(FileTable table[TAM][TAM],int i, int j){
	table[i][j].setX(i);
	table[i][j].setY(j);
	table[i][j].setVal(0);
}

void Table::travelTableInit(){
    for(int i=0; i< TAM; i++)
        for(int j=0; j< TAM; j++)
            initTable(table,i,j);
}

int  Table::numRandom(int limInf, int limSup){
    return limInf+(rand()%((limSup-(limInf))+1));
}

void Table::firstTwoFile(){
    int xVal, yVal, eval, newVal;
    for(int i=0; i<2; i++){
            eval = 0;
        do{
            xVal = numRandom(0,3);
            yVal = numRandom(0,3);
            eval = valuePosRandom(table, xVal, yVal);
        }while(!eval);
        do{
            newVal = numRandom(2,4);
        }while(newVal%2!=0);
        table[xVal][yVal].setVal(newVal);
    }
}

void Table::fileRandomPlay(){
int xVal, yVal, eval = 0, newVal;
    do{
        xVal = numRandom(0,3);
        yVal = numRandom(0,3);
        eval = valuePosRandom(table, xVal, yVal);
    }while(!eval);
    do{
        newVal = numRandom(2,4);
    }while(newVal%2!=0);
    table[xVal][yVal].setVal(newVal);
}

int Table::valuePosRandom(FileTable table[TAM][TAM],int x, int y){
    if(table[x][y].getVal() == 0){
        return 1;
    }
    return 0;
}

void Table::dirMov(){
    int opc, moveF = 0;
    do{
        moveF = 0;
        do{
            cout<<endl;
            cout<<" ** SELECCIONE DIR ** "<<endl;
            cout<<" 1.) UP"<<endl;
            cout<<" 2.) DOWN"<<endl;
            cout<<" 3.) LEFT"<<endl;
            cout<<" 4.) RIGHT"<<endl;
            cin>>opc;
        }while(opc < 1 || opc > 4);
        moveF = moveFile(opc);
        cout<<endl;
        printfTable(table);
        cout<<endl<<endl;
    }while(!moveF);
}

int Table::moveFile(int dir){
    int moveN = 0, moveE = 0, moveF = 0;
    //UP
    if(dir == UP){
        moveN = upMove();
        moveE = upMoveEat();
  //      cout<<endl<<"  --**--> "<<movioE<<endl;
        if(moveE){
            upMove();
        }
    }
    //DOWN
    if(dir == DOWN){
        moveN = downMove();
        moveE = downMoveEat();
        if(moveE){
            downMove();
        }
    }
    //LEFT
    if(dir == LEFT){
        moveN = leftMove();
        moveE = leftMoveEat();
        if(moveE){
            leftMove();
        }
    }
    //RIGHT
    if(dir == RIGH){
        moveN = rightMove();
        moveE = rightMoveEat();
        if(moveE){
            rightMove();
        }
    }
    if(moveE || moveN){
      moveF = 1;
    }
    return moveF;
}
//*********************************************************************
int Table::checkGameOver(FileTable table[TAM][TAM]){
    int nGameOver = 0;
     for(int i= 0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            if(table[i][j].getVal() == 0){
                nGameOver = 1;
            }
            if(!nGameOver){
                nGameOver = upPossibleMoveEat();
            }
            if(!nGameOver){
                nGameOver = downPossibleMoveEat();
            }
            if(!nGameOver){
                nGameOver = leftPossibleMoveEat();
            }
            if(!nGameOver){
                nGameOver = rightPossibleMoveEat();
            }
        }
    }
    return nGameOver;
}
//*********************************************************************

void Table::upPossibleMove(int &pos){
            int j = 0;
        do{
           int i = 1;
            do{
                pos = upPossible(table,i,j);
                i++;
            }while(i < TAM && pos == 0);
            j++;
        }while(j < TAM && pos == 0);
}

void Table::downPossibleMove(int &pos){
    int j = 0;
        do{
           int i = 0;
            do{
                pos = downPossible(table,i,j);
                i++;
            }while(i < TAM-1 && pos == 0);
            j++;
        }while(j < TAM && pos == 0);
}

void Table::leftPossibleMove(int &pos){
        int j = 1;
        do{
           int i = 0;
            do{
                pos = leftPossible(table,i,j);
                i++;
            }while(i < TAM && pos == 0);
            j++;
        }while(j < TAM && pos == 0);
}

void Table::rightPossibleMove(int &pos){
        int j = 0;
        do{
           int i = 0;
            do{
                pos = rightPossible(table,i,j);
                i++;
            }while(i < TAM && pos == 0);
            j++;
        }while(j < TAM-1 && pos == 0);
}


//*********************************************************************
int Table::upMove(){
    int pos;
    int eat = 0, aux;
    do{
        pos = 0;
        for(int i= 1; i<TAM; i++){
            for(int j=0; j<TAM; j++){
                aux = upTable(table,i,j);
                if(aux == 1){
                    eat = 1;
                }
            }
        }
    upPossibleMove(pos);
    }while(pos == 1);
    //cout<<endl<<"-> "<<eat<<endl;
    return eat;
}

int Table::downMove(){
    int pos;
    int eat = 0, aux;
    do{
        pos = 0;
        for(int i= 0; i<TAM-1; i++){
            for(int j=0; j<TAM; j++){
                aux = downTable(table,i,j);
                if(aux == 1){
                    eat = 1;
                }
            }
        }
        downPossibleMove(pos);
    }while(pos == 1);
    return eat;
}

int Table::leftMove(){
    int pos;
    int eat = 0, aux;
    do{
        pos = 0;
        for(int i= 0; i<TAM; i++){
            for(int j=1; j<TAM; j++){
                aux = leftTable(table,i,j);
                if(aux == 1){
                    eat = 1;
                }
            }
        }
        leftPossibleMove(pos);
    }while(pos == 1);
//    cout<<endl<<eat<<endl;
    return eat;
}

int Table::rightMove(){
   int pos;
    int eat = 0, aux;
    do{
        pos = 0;
        for(int i= 0; i<TAM; i++){
            for(int j=0; j<TAM-1; j++){
                aux = rightTable(table,i,j);
                if(aux == 1){
                    eat = 1;
                }
            }
        }
        rightPossibleMove(pos);
    }while(pos == 1);
   // cout<<endl<<eat<<endl;
    return eat;
}

//*********************************************************************

int Table::upMoveEat(){
    int eat = 0, aux;
   for(int i= 1; i<TAM; i++){
        for(int j=0; j<TAM; j++){
           aux = upEat(table,i,j);
          // cout<<"____ "<<aux<<endl;
           if(aux == 1){
                eat = 2;
            }
        }
    }
    return eat;
}
int Table::downMoveEat(){
    int eat = 0, aux;
    for(int i= TAM-1; i>0; i--){
        for(int j=TAM-1; j>=0; j--){
            aux = downEat(table,i,j);
            if(aux == 1){
                eat = 2;
            }
        }
    }
    return eat;
}

int Table::leftMoveEat(){
    int eat = 0, aux;
   for(int i= 0; i<TAM; i++){
        for(int j=1; j<TAM; j++){
            aux = leftEat(table,i,j);
            if(aux == 1){
                eat = 2;
            }
        }
    }
    return eat;
}

int Table::rightMoveEat(){
    int eat = 0, aux;
    for(int i= TAM-1; i>=0; i--){
        for(int j=TAM-1; j>0; j--){
            aux = rightEat(table,i,j);
            if(aux == 1){
                eat = 2;
            }
        }
    }
    return eat;
}
//************************************************************
int Table::upPossibleMoveEat(){
    int eat = 0, aux;
   for(int i= 1; i<TAM; i++){
        for(int j=0; j<TAM; j++){
           aux = upPossibleEat(table,i,j);
           if(aux == 1){
                eat = 2;
            }
        }
    }
    return eat;
}

int Table::downPossibleMoveEat(){
   int eat = 0, aux;
    for(int i= TAM-1; i>0; i--){
        for(int j=TAM-1; j>=0; j--){
            aux = downPossibleEat(table,i,j);
            if(aux == 1){
                eat = 2;
            }
        }
    }
    return eat;
}

int Table::leftPossibleMoveEat(){
    int eat = 0, aux;
   for(int i= 0; i<TAM; i++){
        for(int j=1; j<TAM; j++){
            aux = leftPossibleEat(table,i,j);
            if(aux == 1){
                eat = 2;
            }
        }
    }
    return eat;
}

int Table::rightPossibleMoveEat(){
   int eat = 0, aux;
    for(int i= TAM-1; i>=0; i--){
        for(int j=TAM-1; j>0; j--){
            aux = rightPossibleEat(table,i,j);
            if(aux == 1){
                eat = 2;
            }
        }
    }
    return eat;
}
//********************************************************************************
//falta verificar que efectivamente comio o se movio
int Table::upTable(FileTable table[TAM][TAM],int x, int y){
    //cout<<"("<<table[x-1][y].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
    if(table[x-1][y].getVal() == 0 && table[x][y].getVal() != 0){
        table[x-1][y].setVal(table[x][y].getVal());
        table[x][y].setVal(0);
       // cout<<" ** "<<1<<" ** "<<endl;
        return 1;
    }
        return 0;
}

int Table::downTable(FileTable table[TAM][TAM],int x, int y){
   // cout<<"("<<table[x+1][y].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
    if(table[x+1][y].getVal() == 0 && table[x][y].getVal() != 0){
        table[x+1][y].setVal(table[x][y].getVal());
        table[x][y].setVal(0);
    //    cout<<" ** "<<1<<" ** "<<endl;
        return 1;
    }
        return 0;
}

int Table::leftTable(FileTable table[TAM][TAM],int x, int y){
   // cout<<"("<<table[x][y-1].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
    if(table[x][y-1].getVal() == 0 && table[x][y].getVal() != 0){
        table[x][y-1].setVal(table[x][y].getVal());
        table[x][y].setVal(0);
     //   cout<<" ** "<<1<<" ** "<<endl;
        return 1;
    }
        return 0;
}

int Table::rightTable(FileTable table[TAM][TAM],int x, int y){
   // cout<<"("<<table[x][y+1].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
    if(table[x][y+1].getVal() == 0 && table[x][y].getVal() != 0){
        table[x][y+1].setVal(table[x][y].getVal());
        table[x][y].setVal(0);
       // cout<<" ** "<<1<<" ** "<<endl;
        return 1;
    }
        return 0;
}
//**********************************************************************************
int Table::upPossible(FileTable table[TAM][TAM],int x, int y){
   // cout<<"("<<table[x-1][y].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
    if(table[x-1][y].getVal() == 0 && table[x][y].getVal() != 0){
    //    cout<<" ** "<<1<<" ** "<<endl;
        return 1;
    }
    return 0;
}

int Table::downPossible(FileTable table[TAM][TAM],int x, int y){
   // cout<<"("<<table[x+1][y].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
    if(table[x+1][y].getVal() == 0 && table[x][y].getVal() != 0){
    //    cout<<" ** "<<1<<" ** "<<endl;
        return 1;
    }
    return 0;
}

int Table::leftPossible(FileTable table[TAM][TAM],int x, int y){
   // cout<<"("<<table[x][y-1].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
    if(table[x][y-1].getVal() == 0 && table[x][y].getVal() != 0){
     //   cout<<" ** "<<1<<" ** "<<endl;
        return 1;
    }
    return 0;
}

int Table::rightPossible(FileTable table[TAM][TAM],int x, int y){
    //cout<<"("<<table[x][y+1].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
    if(table[x][y+1].getVal() == 0 && table[x][y].getVal() != 0){
        //cout<<" ** "<<1<<" ** "<<endl;
        return 1;
    }
    return 0;
}

//*******************************************************************************

int Table::upEat(FileTable table[TAM][TAM],int x, int y){
   // cout<<"("<<table[x-1][y].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
   if(table[x-1][y].getVal() == table[x][y].getVal() && table[x][y].getVal() != 0){
        table[x-1][y].setVal(table[x][y].getVal()*2);
        score += table[x][y].getVal()*2;
        table[x][y].setVal(0);
    //    cout<<" **> "<<1<<" <** "<<endl;
        return 1;
    }
        return 0;
}

int Table::downEat(FileTable table[TAM][TAM],int x, int y){
   // cout<<"("<<table[x+1][y].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
   if(table[x-1][y].getVal() == table[x][y].getVal() && table[x][y].getVal() != 0){
        table[x-1][y].setVal(table[x][y].getVal()*2);
        score += table[x][y].getVal()*2;
        table[x][y].setVal(0);
       // cout<<" ** "<<1<<" ** "<<endl;
        return 1;
    }
        return 0;
}

int Table::leftEat(FileTable table[TAM][TAM],int x, int y){
   // cout<<"("<<table[x][y-1].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
   if(table[x][y-1].getVal() == table[x][y].getVal() && table[x][y].getVal() != 0){
        table[x][y-1].setVal(table[x][y].getVal()*2);
        score += table[x][y].getVal()*2;
        table[x][y].setVal(0);
        return 1;
        //cout<<" ** "<<1<<" ** "<<endl;
    }
        return 0;
}

int Table::rightEat(FileTable table[TAM][TAM],int x, int y){
    //cout<<"("<<table[x][y+1].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
   if(table[x][y-1].getVal() == table[x][y].getVal() && table[x][y].getVal() != 0){
        table[x][y-1].setVal(table[x][y].getVal()*2);
        score += table[x][y].getVal()*2;
        table[x][y].setVal(0);
       // cout<<" ** "<<1<<" ** "<<endl;
        return 1;
    }
        return 0;
}

//*****************************************************************


int Table::upPossibleEat(FileTable table[TAM][TAM],int x, int y){
   // cout<<"("<<table[x-1][y].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
   if(table[x-1][y].getVal() == table[x][y].getVal() && table[x][y].getVal() != 0){
    //    cout<<" **> "<<1<<" <** "<<endl;
        return 1;
    }
        return 0;
}

int Table::downPossibleEat(FileTable table[TAM][TAM],int x, int y){
   // cout<<"("<<table[x+1][y].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
   if(table[x-1][y].getVal() == table[x][y].getVal() && table[x][y].getVal() != 0){
       // cout<<" ** "<<1<<" ** "<<endl;
        return 1;
    }
        return 0;
}

int Table::leftPossibleEat(FileTable table[TAM][TAM],int x, int y){
   // cout<<"("<<table[x][y-1].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
   if(table[x][y-1].getVal() == table[x][y].getVal() && table[x][y].getVal() != 0){
        return 1;
        //cout<<" ** "<<1<<" ** "<<endl;
    }
        return 0;
}

int Table::rightPossibleEat(FileTable table[TAM][TAM],int x, int y){
    //cout<<"("<<table[x][y+1].getVal()<<" , "<<table[x][y].getVal()<<")"<<endl;
   if(table[x][y-1].getVal() == table[x][y].getVal() && table[x][y].getVal() != 0){
       // cout<<" ** "<<1<<" ** "<<endl;
        return 1;
    }
        return 0;
}

