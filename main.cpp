#include <iostream>
#include <vector>

#include "include/tipografia.h"
#include "include/crud.h"
#include "include/archivos.h"
#include "include/ordenacion.h"
#include "include/busqueda.h"
#include "include/intercalacion.h"
#include "include/reporte.h"
#include "include/utilidades.h"

using namespace std;

int main()
{
    vector<Tipografia> tipografias;

    cargarTipografias(
        "data/tipoprueba.csv",
        tipografias
    );

    int opcion=-1;

    while(opcion!=0)
    {
        mostrarMenu();

        cin>>opcion;

        switch(opcion)
        {
        //REGISTRAR
        case 1:

            crearTipografia(
                tipografias
            );

            guardarTipografias(
                "data/tipoprueba.csv",
                tipografias
            );

            break;

        //LISTAR
        case 2:

            listarTipografias(
                tipografias
            );

            break;

        //ORDENAR
        case 3:

            compararOrdenamientos(
                tipografias
            );

            guardarTipografias(
                "data/tipoprueba.csv",
                tipografias
            );

            cout<<"\nTipografias ordenadas.\n";

            break;

        //MODIFICAR
        case 4:

            modificarTipografia(
                tipografias
            );

            guardarTipografias(
                "data/tipoprueba.csv",
                tipografias
            );

            break;

        //ELIMINAR
        case 5:

            eliminarTipografia(
                tipografias
            );

            guardarTipografias(
                "data/tipoprueba.csv",
                tipografias
            );

            break;

        //BUSCAR
        case 6:
        {
            if(tipografias.empty())
            {
                cout<<"\nNo existen registros.\n";

                break;
            }

            int opcionBusqueda;

            cout<<"\n1. Buscar por nombre\n";
            cout<<"2. Buscar por codigo\n";
            cout<<"\nSeleccione opcion: ";

            cin>>opcionBusqueda;

            if(opcionBusqueda==1)
            {
                int compTemp=0;
                int intTemp=0;

                ordenarBubble(
                    tipografias,
                    compTemp,
                    intTemp
                );

                string nombreBuscado;

                cout<<"\nNombre: ";
                cin>>nombreBuscado;

                cout<<"\n1. Binaria Iterativa\n";
                cout<<"2. Binaria Recursiva\n";

                int metodo;

                cout<<"\nSeleccione opcion: ";
                cin>>metodo;

                int posicion=-1;
                int comparaciones=0;

                if(metodo==1)
                {
                    posicion=
                    busquedaBinariaIterativa(
                        tipografias,
                        nombreBuscado,
                        comparaciones
                    );
                }
                else
                {
                    posicion=
                    busquedaBinariaRecursiva(
                        tipografias,
                        0,
                        tipografias.size()-1,
                        nombreBuscado,
                        comparaciones
                    );
                }

                if(posicion!=-1)
                {
                    cout<<"\n===== ENCONTRADO =====\n";

                    cout<<"Codigo: "
                        <<tipografias[posicion].codigo
                        <<endl;

                    cout<<"Nombre: "
                        <<tipografias[posicion].nombre
                        <<endl;

                    cout<<"Categoria: "
                        <<tipografias[posicion].categoria
                        <<endl;

                    cout<<"Autor: "
                        <<tipografias[posicion].autor
                        <<endl;

                    cout<<"Fecha: "
                        <<tipografias[posicion].fecha
                        <<endl;

                    cout<<"\nComparaciones: "
                        <<comparaciones
                        <<endl;
                }
                else
                {
                    cout<<"\nTipografia no encontrada.\n";
                }
            }
            else
            {
                string codigoBuscado;

                cout<<"\nCodigo: ";
                cin>>codigoBuscado;

                int posicion=
                busquedaSecuencialCodigo(
                    tipografias,
                    codigoBuscado
                );

                if(posicion!=-1)
                {
                    cout<<"\n===== ENCONTRADO =====\n";

                    cout<<"Codigo: "
                        <<tipografias[posicion].codigo
                        <<endl;

                    cout<<"Nombre: "
                        <<tipografias[posicion].nombre
                        <<endl;

                    cout<<"Categoria: "
                        <<tipografias[posicion].categoria
                        <<endl;

                    cout<<"Autor: "
                        <<tipografias[posicion].autor
                        <<endl;

                    cout<<"Fecha: "
                        <<tipografias[posicion].fecha
                        <<endl;
                }
                else
                {
                    cout<<"\nTipografia no encontrada.\n";
                }
            }

            break;
        }

        //INTERCALACION
        case 7:
        {
            vector<Tipografia> tipografias1;
            vector<Tipografia> tipografias2;
            vector<Tipografia> resultado;

            cargarTipografias(
                "data/tipografias1.csv",
                tipografias1
            );

            cargarTipografias(
                "data/tipografias2.csv",
                tipografias2
            );

            cout<<"\nArchivo 1: "
                <<tipografias1.size()
                <<" registros\n";

            cout<<"Archivo 2: "
                <<tipografias2.size()
                <<" registros\n";

            int comp1=0;
            int int1=0;

            int comp2=0;
            int int2=0;

            ordenarBubble(
                tipografias1,
                comp1,
                int1
            );

            ordenarBubble(
                tipografias2,
                comp2,
                int2
            );

            resultado=
            intercalarTipografias(
                tipografias1,
                tipografias2
            );

            guardarTipografias(
                "data/resultado.csv",
                resultado
            );

            cout<<"\nResultado: "
                <<resultado.size()
                <<" registros\n";

            cout<<"\nIntercalacion completada.\n";
            cout<<"Archivo generado: data/resultado.csv\n";

            break;
        }

        //REPORTE
        case 8:

            generarReportePDF(
                tipografias
            );

            break;

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