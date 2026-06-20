#include <iostream>
#include <vector>

#include "../include/crud.h"

using namespace std;

void crearTipografia(vector<Tipografia> &tipografias)
{
    Tipografia t;

    cout<<"Codigo: ";
    cin>>t.codigo;

    cout<<"Nombre: ";
    cin>>t.nombre;

    cout<<"Categoria: ";
    cin>>t.categoria;

    cout<<"Autor: ";
    cin>>t.autor;

    cout<<"Fecha: ";
    cin>>t.fecha;

    tipografias.push_back(t);

    cout<<"\nTipografia registrada.\n";
}

void listarTipografias(const vector<Tipografia> &tipografias)
{
    if(tipografias.empty())
    {
        cout<<"\nNo existen registros.\n";
        return;
    }

    for(int i=0;i<tipografias.size();i++)
    {
        cout<<"\nRegistro #"<<i+1<<endl;

        cout<<"Codigo: "
            <<tipografias[i].codigo
            <<endl;

        cout<<"Nombre: "
            <<tipografias[i].nombre
            <<endl;

        cout<<"Categoria: "
            <<tipografias[i].categoria
            <<endl;

        cout<<"Autor: "
            <<tipografias[i].autor
            <<endl;

        cout<<"Fecha: "
            <<tipografias[i].fecha
            <<endl;
    }
}

void modificarTipografia(vector<Tipografia> &tipografias)
{
    string codigo;

    cout<<"Codigo a modificar: ";
    cin>>codigo;

    for(int i=0;i<tipografias.size();i++)
    {
        if(tipografias[i].codigo==codigo)
        {
            cout<<"Nuevo nombre: ";
            cin>>tipografias[i].nombre;

            cout<<"Nueva categoria: ";
            cin>>tipografias[i].categoria;

            cout<<"Nuevo autor: ";
            cin>>tipografias[i].autor;

            cout<<"Nueva fecha: ";
            cin>>tipografias[i].fecha;

            cout<<"\nRegistro modificado.\n";

            return;
        }
    }

    cout<<"\nTipografia no encontrada.\n";
}

void eliminarTipografia(vector<Tipografia> &tipografias)
{
    string codigo;

    cout<<"Codigo a eliminar: ";
    cin>>codigo;

    for(int i=0;i<tipografias.size();i++)
    {
        if(tipografias[i].codigo==codigo)
        {
            tipografias.erase(tipografias.begin()+i);

            cout<<"\nRegistro eliminado.\n";

            return;
        }
    }

    cout<<"\nTipografia no encontrada.\n";
}