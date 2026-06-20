#include <fstream>
#include <iostream>

#include "../include/reporte.h"

using namespace std;

void generarReportePDF(
    const vector<Tipografia> &tipografias
)
{
    ofstream archivo("data/reporte.pdf");

    if(!archivo)
    {
        cout<<"\nError al generar reporte.\n";
        return;
    }

    archivo<<"REPORTE DE TIPOGRAFIAS\n\n";

    for(int i=0;i<tipografias.size();i++)
    {
        archivo<<"Codigo: "
               <<tipografias[i].codigo
               <<"\n";

        archivo<<"Nombre: "
               <<tipografias[i].nombre
               <<"\n";

        archivo<<"Categoria: "
               <<tipografias[i].categoria
               <<"\n";

        archivo<<"Autor: "
               <<tipografias[i].autor
               <<"\n";

        archivo<<"Fecha: "
               <<tipografias[i].fecha
               <<"\n\n";
    }

    archivo.close();

    cout<<"\nReporte generado: data/reporte.pdf\n";
}