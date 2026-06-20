#include <vector>

#include "../include/intercalacion.h"

using namespace std;

vector<Tipografia> intercalarTipografias(const vector<Tipografia> &v1,const vector<Tipografia> &v2)
{
    vector<Tipografia> resultado;

    int i=0;
    int j=0;

    while(i<v1.size() && j<v2.size())
    {
        if(v1[i].nombre<=v2[j].nombre)
        {
            resultado.push_back(v1[i]);
            i++;
        }
        else
        {
            resultado.push_back(v2[j]);
            j++;
        }
    }

    while(i<v1.size())
    {
        resultado.push_back(v1[i]);
        i++;
    }

    while(j<v2.size())
    {
        resultado.push_back(v2[j]);
        j++;
    }

    return resultado;
}