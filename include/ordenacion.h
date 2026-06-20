#ifndef ORDENACION_H
#define ORDENACION_H

#include <vector>

#include "tipografia.h"

using namespace std;

//BUBBLE SORT
void ordenarBubble(
    vector<Tipografia> &tipografias,
    int &comparaciones,
    int &intercambios
);

//MERGE SORT
void mergeSort(
    vector<Tipografia> &tipografias,
    int izquierda,
    int derecha,
    int &comparaciones,
    int &intercambios
);

//COMPARACION
void compararOrdenamientos(
    vector<Tipografia> &tipografias
);

//ORDENAR POR CATEGORIA
void ordenarPorCategoria(
    vector<Tipografia> &tipografias
);

#endif