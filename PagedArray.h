

#ifndef TAREACORTA1_SIMPLEMATRIX_H
#define TAREACORTA1_SIMPLEMATRIX_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

class PagedArray {

    int paginas;
    char* arch_salida;
    int numXpagina;
    int* Pag_cargada;
    int** pagesPtr;

public:
    PagedArray(char* arch_salida, int paginas, int numXpagina);
    int getNumAt(int row, int column);
    void setNumAt(int row, int column, int num);
    bool isLoaded(int pageNmbr);
    void loadPage(int pageNumber);
    int freeSpace(int ref);
    void swap(int i, int j);
    void unloadPage(int pageNumber, int virtual_pageNumber);
    int gotFreeSpace();
    string getLine(int lineNumber);
    int operator[](int position);
    void releaseMem();



};


#endif //TAREACORTA1_SIMPLEMATRIX_H
