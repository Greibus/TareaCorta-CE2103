//
// Created by tony on 19/03/18.
//

#include "prueba.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;

int * prueba::array() {
    int array[1000];
    char *txt = "";

    int * pointer = array;
    srand(time(NULL));

    for (int i = 0; i < 1000; i++) {
        array[i] =(char) rand();
        cout<<array[i]<<endl;

        txt += (char)array[i];


    }

    //cout<<txt<<endl;
    ofstream file;
    file.open("/Users/edgarchaves/Desktop/Prueba/Hola.txt");
    //file<<txt;
    file.write("Hola",10000);

    file.close();
    //fstream *fs= new fstream("/Users/edgarchaves/Desktop/Prueba.txt",ios::out|ios::binary);

    //fs->write(txt,1000);
    //fs->close();
    return pointer;
}