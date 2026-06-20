#include <vector>
#include <string>

#include "../include/busqueda.h"

using namespace std;

//SECUENCIAL NOMBRE
int busquedaSecuencialNombre(
    const vector<Tipografia> &tipografias,
    string nombre
)
{
    for(int i=0;i<tipografias.size();i++)
    {
        if(tipografias[i].nombre==nombre)
        {
            return i;
        }
    }

    return -1;
}

//SECUENCIAL CODIGO
int busquedaSecuencialCodigo(
    const vector<Tipografia> &tipografias,
    string codigo
)
{
    for(int i=0;i<tipografias.size();i++)
    {
        if(tipografias[i].codigo==codigo)
        {
            return i;
        }
    }

    return -1;
}

//BINARIA ITERATIVA
int busquedaBinariaIterativa(
    const vector<Tipografia> &tipografias,
    string nombre,
    int &comparaciones
)
{
    comparaciones=0;

    int izquierda=0;
    int derecha=tipografias.size()-1;

    while(izquierda<=derecha)
    {
        comparaciones++;

        int medio=(izquierda+derecha)/2;

        if(tipografias[medio].nombre==nombre)
        {
            return medio;
        }

        if(nombre<tipografias[medio].nombre)
        {
            derecha=medio-1;
        }
        else
        {
            izquierda=medio+1;
        }
    }

    return -1;
}

//BINARIA RECURSIVA
int busquedaBinariaRecursiva(
    const vector<Tipografia> &tipografias,
    int izquierda,
    int derecha,
    string nombre,
    int &comparaciones
)
{
    if(izquierda>derecha)
    {
        return -1;
    }

    comparaciones++;

    int medio=(izquierda+derecha)/2;

    if(tipografias[medio].nombre==nombre)
    {
        return medio;
    }

    if(nombre<tipografias[medio].nombre)
    {
        return busquedaBinariaRecursiva(
            tipografias,
            izquierda,
            medio-1,
            nombre,
            comparaciones
        );
    }

    return busquedaBinariaRecursiva(
        tipografias,
        medio+1,
        derecha,
        nombre,
        comparaciones
    );
}