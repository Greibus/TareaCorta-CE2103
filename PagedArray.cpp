//
// Created by gerardo on 13/03/17.
//

#include "PagedArray.h"
#include <sstream>


using namespace std;

PagedArray::PagedArray(char* arch_salida, int paginas, int numXpagina){
    this->paginas = paginas;
    this->numXpagina = numXpagina;
    this->arch_salida = arch_salida;

    this->pagesPtr = (int**) malloc(6* sizeof(int*));
    this->Pag_cargada = (int*) malloc(6* sizeof(int));

    for(int i = 0; i < paginas ; i++){
        *(this->Pag_cargada+i) = -1;
    }

    for(int i = 0; i < paginas ; i++){
        int* ptr = (int*)malloc(256*sizeof(int));
        for (int j = 0; j < numXpagina ; j++){
            *(ptr+j) = 0;
        }
        *(pagesPtr+i) = ptr;
    }
}

void PagedArray::unloadPage(int pageNumber, int virtual_pageNumber) {
    string line = "";
    ostringstream os("");
    int in = 0;
    for(int j = 0; j < numXpagina ; j++) {
        os << *(((*pagesPtr + pageNumber)) + j);
        line += os.str() + ",";
        os.str("");
        in ++;
    }

    fstream inFile;
    inFile.open(this->arch_salida);
    string finalText = "";
    string tempLine;
    for(int lineo = 0; std::getline(inFile,tempLine); lineo++){
        if(lineo == virtual_pageNumber){
            tempLine = line;
        }
        finalText += tempLine + "\n";
    }

    inFile.close();
    remove(this->arch_salida);
    ofstream outFile;
    outFile.open(this->arch_salida);
    outFile << finalText;
    outFile.close();
}


bool PagedArray::isLoaded(int pageNmbr) {
    int i = 0;
    while(i < this->paginas){
        if(*(this->Pag_cargada+i) == pageNmbr){
            return true;
        }
        i++;
    }
    return false;
}

string PagedArray::getLine(int lineNumber) {
    fstream file;
    file.open(this->arch_salida);

    string line = "";
    for(int lineo = 0; getline(file,line);lineo++){
        if(lineo == lineNumber){
            return line;
        }
    }
    file.close();
    return line;
}

int PagedArray::gotFreeSpace() {
    int i = 0;
    while(i < this->paginas){
        if(*(this->Pag_cargada+i) == -1){
            return i;
        }
        i++;
    }
    return -1;
}

int PagedArray::freeSpace(int ref) {
    int greatest_num = -1;
    int ii = 0;
    for (int i = 0 ; i < this->paginas ; i++){
        if(abs((*(this->Pag_cargada+i))-ref) > greatest_num){
            greatest_num = abs((*(this->Pag_cargada+i))-ref);
            ii = i;
        }
    }
    return ii;
}

void PagedArray::loadPage(int pageNumber) {
    std::string line = getLine(pageNumber);
    int space = gotFreeSpace();
    if(space == -1){
        space = freeSpace(pageNumber);

        unloadPage(space,*(Pag_cargada+space));
    }
    *(this->Pag_cargada+space) = pageNumber;
    std::string str = "";
    int ptrI = 0;
    int j =0;
    for(char& c : line){
        if(c == ',' && str != ""){
            *((*(pagesPtr+space))+ptrI) =  std::stoi(str);
            str = "";
            ptrI++;
        }else if(c != ',' && c != '\n'){
            str += c;
        }
    }
}

int PagedArray::getNumAt(int row, int column) {
    if(!isLoaded(row)){
        loadPage(row);
    }
    for(int i = 0 ; i < this->paginas ; i++){
        if(*(Pag_cargada + i) == row) {
            for(int j = 0 ; j < numXpagina ; j++){
                if(j==column){
                    return *((*(pagesPtr+i))+j);
                }
            }
        }
    }
    return -1;
}

void PagedArray::setNumAt(int row, int column, int num) {
    if(!isLoaded(row)){
        loadPage(row);
    }
    for(int i = 0 ; i < this->paginas ; i++){
        if(*(Pag_cargada + i)  == row) {
            for(int j = 0 ; j < numXpagina ; j++){
                if(j==column){
                    *((*(pagesPtr+i))+j) = num;
                }
            }
        }
    }
}


int PagedArray::operator[](int position) {
    int neededPage = (position / this->numXpagina);
    int num = getNumAt(neededPage,position % this->numXpagina);
    return num;
}


void PagedArray::swap(int i, int j) {
    int num_i = getNumAt((i/this->numXpagina),i%this->numXpagina);
    int num_j = getNumAt((j/this->numXpagina),j%this->numXpagina);
    setNumAt((i/this->numXpagina),i%this->numXpagina,num_j);
    setNumAt((j/this->numXpagina),j%this->numXpagina,num_i);

}


void PagedArray::releaseMem() {
    for(int i = 0; i < paginas ; i++){
        if((*Pag_cargada+i) != -1){
            unloadPage(i,*(Pag_cargada+i));
        }
    }
}


