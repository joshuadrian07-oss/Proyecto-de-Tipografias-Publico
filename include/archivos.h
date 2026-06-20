#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <fstream>
#include <vector>
#include <string>

#include "tipografia.h"

using namespace std;

bool leerTipografiaCSV(ifstream &archivo,Tipografia &t);
void cargarTipografias(const string &nombreArchivo,vector<Tipografia> &tipografias);
void guardarTipografias(const string &nombreArchivo,const vector<Tipografia> &tipografias);

#endif