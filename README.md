# Sistema de Gestión de Tipografías

Universidad Católica Boliviana "San Pablo" Programación I (SIS-112) Examen Final Integrador – Gestión 1/2026

Integrantes

Joshua Adrian Oña Gutierrez
Docente: Pamela Shirley Valenzuela Fernández

Descripción del Proyecto

El Sistema de Gestión de Tipografías es una aplicación desarrollada en C++ que permite administrar un catálogo de tipografías mediante operaciones CRUD y persistencia de datos utilizando archivos CSV.

Dominio de Datos

Código
Nombre
Categoría
Autor
Fecha
Struct Principal

cpp struct Tipografia { string codigo; string nombre; string categoria; string autor; string fecha; };

Estructura del Proyecto

ProyectoTipografias/

include/
src/
data/
main.cpp
README.md
Algoritmos Implementados

Bubble Sort Normal
Bubble Sort Optimizado
Búsqueda Secuencial
Búsqueda Binaria Iterativa
Búsqueda Binaria Recursiva
Intercalación
Compilación

bash g++ main.cpp src/*.cpp -Iinclude -o tipografias

Ejecución

Para Windows: tipografias.exe

En Linux: ./tipografias
