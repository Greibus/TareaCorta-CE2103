//
// Created by tony on 19/03/18.
//

#include "prueba.h"
#include <stdlib.h>
#include <time.h>

int * prueba::array() {
    int array[1000];
    int * pointer = array;
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        array[i] = rand();
    }
    return pointer;
}