#include <iostream>
#include <vector>

#include "tipografia.h"
#include "crud.h"
#include "archivos.h"
#include "ordenacion.h"
#include "busqueda.h"
#include "intercalacion.h"
#include "utilidades.h"

using namespace std;

int main()
{
    vector<Tipografia> tipografias;

    cargarTipografias("data/tipoprueba.csv",tipografias);

    int opcion=-1;

    while(opcion!=0)
    {
        mostrarMenu();

        cin>>opcion;

        switch(opcion)
        {
        //REGISTRAR
        case 1:

            crearTipografia(tipografias);
            guardarTipografias("data/tipoprueba.csv",tipografias);

            break;

        //LISTAR
        case 2:

            listarTipografias(tipografias);

            break;

        //ORDENAR
        case 3:
        {
            vector<Tipografia> copia=tipografias;

            int compNormal=0;
            int intNormal=0;

            int compOpt=0;
            int intOpt=0;

            bubbleSortNormal(copia,compNormal,intNormal);

            bubbleSortOptimizado(tipografias,compOpt,intOpt);

            guardarTipografias("data/tipoprueba.csv",tipografias);

            cout<<"\n===== REPORTE DE EFICIENCIA =====\n";

            cout<<"\nBubble Sort Normal\n";
            cout<<"Comparaciones: "<<compNormal<<endl;
            cout<<"Intercambios: "<<intNormal<<endl;

            cout<<"\nBubble Sort Optimizado\n";
            cout<<"Comparaciones: "<<compOpt<<endl;
            cout<<"Intercambios: "<<intOpt<<endl;

            cout<<"\nTipografias ordenadas.\n";

            break;
        }

        //MODIFICAR
        case 4:

            modificarTipografia(tipografias);
            guardarTipografias("data/tipoprueba.csv",tipografias);

            break;

        //ELIMINAR
        case 5:

            eliminarTipografia(tipografias);
            guardarTipografias("data/tipoprueba.csv",tipografias);

            break;

        //BUSCAR
        case 6:
        {
            if(tipografias.empty())
            {
                cout<<"\nNo existen tipografias registradas.\n";

                break;
            }

            int compTemp=0;
            int intTemp=0;

            bubbleSortOptimizado(tipografias,compTemp,intTemp);

            string nombreBuscado;

            cout<<"\nIngrese el nombre de la tipografia: ";
            cin>>nombreBuscado;

            cout<<"\n1. Busqueda Binaria Iterativa\n";
            cout<<"2. Busqueda Binaria Recursiva\n";

            int opcionBusqueda;

            cout<<"Seleccione opcion: ";
            cin>>opcionBusqueda;

            int posicion=-1;
            int comparaciones=0;

            if(opcionBusqueda==1)
            {
                posicion=busquedaBinariaIterativa(tipografias,nombreBuscado,comparaciones);
            }
            else
            {
                posicion=busquedaBinariaRecursiva(tipografias,0,tipografias.size()-1,nombreBuscado,comparaciones);
            }

            if(posicion!=-1)
            {
                cout<<"\n===== TIPOGRAFIA ENCONTRADA =====\n";

                cout<<"Codigo: "<<tipografias[posicion].codigo<<endl;
                cout<<"Nombre: "<<tipografias[posicion].nombre<<endl;
                cout<<"Categoria: "<<tipografias[posicion].categoria<<endl;
                cout<<"Autor: "<<tipografias[posicion].autor<<endl;
                cout<<"Fecha: "<<tipografias[posicion].fecha<<endl;

                cout<<"\nComparaciones realizadas: "<<comparaciones<<endl;
            }
            else
            {
                cout<<"\nTipografia no encontrada.\n";
            }

            break;
        }

        //INTERCALACION
        case 7:
        {
            vector<Tipografia> tipografias1;
            vector<Tipografia> tipografias2;
            vector<Tipografia> resultado;

            cargarTipografias("data/tipografias1.csv",tipografias1);
            cargarTipografias("data/tipografias2.csv",tipografias2);

            cout<<"\nArchivo 1: "<<tipografias1.size()<<" registros\n";
            cout<<"Archivo 2: "<<tipografias2.size()<<" registros\n";

            int comp1=0;
            int int1=0;

            int comp2=0;
            int int2=0;

            bubbleSortOptimizado(tipografias1,comp1,int1);
            bubbleSortOptimizado(tipografias2,comp2,int2);

            resultado=intercalarTipografias(tipografias1,tipografias2);

            cout<<"Resultado: "<<resultado.size()<<" registros\n";

            guardarTipografias("data/resultado.csv",resultado);

            cout<<"\nIntercalacion completada.\n";
            cout<<"Archivo generado: data/resultado.csv\n";

            break;
        }

        //SALIR
        case 0:

            cout<<"\nSaliendo del sistema...\n";

            break;

        //ERROR
        default:

            cout<<"\nOpcion invalida.\n";
        }
    }

    return 0;
}