#ifndef FILETABLE_H
#define FILETABLE_H

#include <iostream>
using namespace std;

class FileTable
{
public:
    FileTable(void);
    virtual ~FileTable(void);

	void setX ( int x );
    int getX ( void );

    void setY ( int y );
    int getY ( void );

    void setVal ( int val );
    int getVal ( void );

protected:
    int x;
    int y;
    int val;
};

#endif // FICHA_H
