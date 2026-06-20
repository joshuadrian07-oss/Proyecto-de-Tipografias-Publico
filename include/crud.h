#ifndef CRUD_H
#define CRUD_H

#include <vector>

#include "tipografia.h"

using namespace std;

void crearTipografia(vector<Tipografia> &tipografias);
void listarTipografias(const vector<Tipografia> &tipografias);
void modificarTipografia(vector<Tipografia> &tipografias);
void eliminarTipografia(vector<Tipografia> &tipografias);

#endif