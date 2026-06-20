#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include <string>

#include "tipografia.h"

using namespace std;

//SECUENCIAL POR NOMBRE
int busquedaSecuencialNombre(
    const vector<Tipografia> &tipografias,
    string nombre
);

//SECUENCIAL POR CODIGO
int busquedaSecuencialCodigo(
    const vector<Tipografia> &tipografias,
    string codigo
);

//BINARIA ITERATIVA
int busquedaBinariaIterativa(
    const vector<Tipografia> &tipografias,
    string nombre,
    int &comparaciones
);

//BINARIA RECURSIVA
int busquedaBinariaRecursiva(
    const vector<Tipografia> &tipografias,
    int izquierda,
    int derecha,
    string nombre,
    int &comparaciones
);

#endif