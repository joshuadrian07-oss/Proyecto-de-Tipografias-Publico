#include <iostream>
#include <fstream>
#include <sstream>

#include "../include/archivos.h"

using namespace std;

bool leerTipografiaCSV(ifstream &archivo,Tipografia &t)
{
    string linea;

    if(!getline(archivo,linea))
    {
        return false;
    }

    stringstream ss(linea);

    getline(ss,t.codigo,',');
    getline(ss,t.nombre,',');
    getline(ss,t.categoria,',');
    getline(ss,t.autor,',');
    getline(ss,t.fecha,',');

    return true;
}

void cargarTipografias(const string &nombreArchivo,vector<Tipografia> &tipografias)
{
    ifstream archivo(nombreArchivo);

    if(!archivo)
    {
        return;
    }

    Tipografia temp;

    while(leerTipografiaCSV(archivo,temp))
    {
        tipografias.push_back(temp);
    }

    archivo.close();
}

void guardarTipografias(const string &nombreArchivo,const vector<Tipografia> &tipografias)
{
    ofstream archivo(nombreArchivo);

    for(int i=0;i<tipografias.size();i++)
    {
        archivo
        << tipografias[i].codigo << ","
        << tipografias[i].nombre << ","
        << tipografias[i].categoria << ","
        << tipografias[i].autor << ","
        << tipografias[i].fecha
        << endl;
    }

    archivo.close();
}