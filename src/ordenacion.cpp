#include <iostream>
#include <vector>

#include "../include/ordenacion.h"

using namespace std;

//MERGE AUXILIAR
void merge(
    vector<Tipografia> &tipografias,
    int izquierda,
    int medio,
    int derecha,
    int &comparaciones,
    int &intercambios
)
{
    vector<Tipografia> temporal;

    int i=izquierda;
    int j=medio+1;

    while(i<=medio && j<=derecha)
    {
        comparaciones++;

        if(tipografias[i].nombre<=tipografias[j].nombre)
        {
            temporal.push_back(tipografias[i]);
            i++;
        }
        else
        {
            temporal.push_back(tipografias[j]);
            j++;
            intercambios++;
        }
    }

    while(i<=medio)
    {
        temporal.push_back(tipografias[i]);
        i++;
    }

    while(j<=derecha)
    {
        temporal.push_back(tipografias[j]);
        j++;
    }

    for(int k=0;k<temporal.size();k++)
    {
        tipografias[izquierda+k]=temporal[k];
    }
}

//BUBBLE SORT
void ordenarBubble(
    vector<Tipografia> &tipografias,
    int &comparaciones,
    int &intercambios
)
{
    comparaciones=0;
    intercambios=0;

    Tipografia aux;
    bool intercambio;

    for(int i=0;i<tipografias.size()-1;i++)
    {
        intercambio=false;

        for(int j=0;j<tipografias.size()-i-1;j++)
        {
            comparaciones++;

            if(tipografias[j].nombre>
               tipografias[j+1].nombre)
            {
                aux=tipografias[j];
                tipografias[j]=tipografias[j+1];
                tipografias[j+1]=aux;

                intercambios++;
                intercambio=true;
            }
        }

        if(intercambio==false)
        {
            break;
        }
    }
}

//MERGE SORT
void mergeSort(
    vector<Tipografia> &tipografias,
    int izquierda,
    int derecha,
    int &comparaciones,
    int &intercambios
)
{
    if(izquierda<derecha)
    {
        int medio=(izquierda+derecha)/2;

        mergeSort(
            tipografias,
            izquierda,
            medio,
            comparaciones,
            intercambios
        );

        mergeSort(
            tipografias,
            medio+1,
            derecha,
            comparaciones,
            intercambios
        );

        merge(
            tipografias,
            izquierda,
            medio,
            derecha,
            comparaciones,
            intercambios
        );
    }
}

//COMPARACION
void compararOrdenamientos(
    vector<Tipografia> &tipografias
)
{
    vector<Tipografia> bubble=tipografias;
    vector<Tipografia> mergeVector=tipografias;

    int compBubble=0;
    int intBubble=0;

    int compMerge=0;
    int intMerge=0;

    ordenarBubble(
        bubble,
        compBubble,
        intBubble
    );

    if(!mergeVector.empty())
    {
        mergeSort(
            mergeVector,
            0,
            mergeVector.size()-1,
            compMerge,
            intMerge
        );
    }

    cout<<"\n===== REPORTE DE EFICIENCIA =====\n";

    cout<<"\nBubble Sort\n";
    cout<<"Comparaciones: "<<compBubble<<endl;
    cout<<"Intercambios: "<<intBubble<<endl;
    cout<<"Total: "<<compBubble+intBubble<<endl;

    cout<<"\nMerge Sort\n";
    cout<<"Comparaciones: "<<compMerge<<endl;
    cout<<"Intercambios: "<<intMerge<<endl;
    cout<<"Total: "<<compMerge+intMerge<<endl;

    if(
        (compBubble+intBubble)
        <
        (compMerge+intMerge)
    )
    {
        cout<<"\nMetodo mas eficiente: Bubble Sort\n";
    }
    else
    {
        cout<<"\nMetodo mas eficiente: Merge Sort\n";
    }

    tipografias=mergeVector;
}

//ORDENAR POR CATEGORIA
void ordenarPorCategoria(
    vector<Tipografia> &tipografias
)
{
    Tipografia aux;

    for(int i=0;i<tipografias.size()-1;i++)
    {
        for(int j=0;j<tipografias.size()-i-1;j++)
        {
            if(
                tipografias[j].categoria>
                tipografias[j+1].categoria
            )
            {
                aux=tipografias[j];
                tipografias[j]=tipografias[j+1];
                tipografias[j+1]=aux;
            }
        }
    }
}