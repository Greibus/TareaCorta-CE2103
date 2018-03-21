

#include <iostream>
#include <fstream>
#include <string.h>
#include "prueba.h"
#include "PagedArray.h"

using namespace std;


/*int cuenta=0;

void reordena(string cadena, char* Archivo){
    ofstream file;
    file.open(Archivo, ios::trunc);
    int cont  = 0;
    for(int i=0; i<cadena.length(); i++){
        if (cadena.at(i) == ','){
            file << cadena.at(i);
            cont++;
            cuenta++;
        }
        else if (cont % 256 == 0 && cont != 0){
            file << "\n";
            file << cadena.at(i);
            cont=0;
        }
        else if (cadena.at(i) != 0){
            file << cadena.at(i);
        }
    }
    file.close();
}

void leer(char* archivo, char* arch_salida) {

    fstream file;
    file.open(archivo);
    string str = string((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close();

    reordena(str, arch_salida);
}

void QuickSort(PagedArray* pagedArray, int left, int right){
    int pivot = pagedArray->operator[]((left+right)/2);
    int i = left;
    int j = right;

    do{
        while(pagedArray->operator[](i) < pivot)i++;
        while(pagedArray->operator[](j) > pivot)j--;
        if(i <= j){
            pagedArray->swap(i , j);
            i++;
            j--;
        }
    }while(i <= j);
    if(left < j)QuickSort(pagedArray,left, j);
    if(i < right)QuickSort(pagedArray,i,right);
}


void InsertionSort(PagedArray* pagedArray, int N) {

    for(int i = 1; i < N; i++){
        for(int j = i; j > 0; j--){
            if(pagedArray->operator[](j) < pagedArray->operator[](j-1)){
                pagedArray->swap(j,j-1);
            }
        }
    }
}


void SelectionSort(PagedArray * pagedArray, int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        int j;
        for(j = i; j < size; j++){
            int a = pagedArray->operator[](j);
            int b = pagedArray->operator[](minIndex);
            if(a < b){
                minIndex = j;
            }
        }
        if(minIndex != i) pagedArray->swap(i, minIndex);

    }
}

*/
int main(int args, char* arg[]) {
    prueba * prueba1 = new prueba();
    prueba1->array();
    cout<<prueba1->array()<<endl;
    PagedArray* pagedArray = new PagedArray("_DS_Store",6,256);
    pagedArray->releaseMem();




    return 0;





  /*  char* arch_entrada = new char;
    char* arch_salida = new char;
    char* Algoritmo = new char;

    if (args < 7) {
        cout << "Para usar digite: paged-sort -i <archivo> -a {QS|IS|SS} -o <archivo_resultado>" << endl;
        cout << " **Cambie <> por el nombre del archivo y {} por el algoritmo a usar**" << endl;
        cin.get();
        exit(0);
    } else {
        cout << arg[0];
        for (int i = 1; i < args; i++) {
            if (i + 1 != args) {
                if (strcmp(arg[i], "paged-sort")==0) {
                } else if (strcmp(arg[i] , "-i")==0) {
                    arch_entrada = arg[++i];
                } else if (strcmp(arg[i] , "-a")==0) {
                    Algoritmo = arg[++i];
                } else if (strcmp(arg[i] , "-o")==0) {
                    arch_salida = arg[++i];
                } else {
                    cout << "Uno o varios parametros son incorrectos. Por favor intente de nuevo." << endl;
                    exit(0);
                }

            }
        }
    }

    leer(arch_entrada, arch_salida);


    PagedArray* pagedArray = new PagedArray(arch_salida,6,256);

    if(strcmp(Algoritmo,"QS")==0){
        QuickSort(pagedArray,0,cuenta-1);
    }else if(strcmp(Algoritmo,"IS")==0){
        InsertionSort(pagedArray,cuenta);
    }else if(strcmp(Algoritmo,"SS")==0){
        SelectionSort(pagedArray,cuenta);
    }else{
        cout << "Codigo de Algoritmo incorrecto, seleccione solo alguno de estos: {QS|IS|SS}" << endl;
        exit(0);
    }

    pagedArray->releaseMem();

    return 0;
    */
}

