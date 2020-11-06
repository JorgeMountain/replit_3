#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <iostream>
#include<fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;



void cajero(string archivo_admin, string archivo_usr, int metodo,int  n);
void escribir_txt(string name, string data);
string leer_txt(string name);



bool verificar_admin(string archivo, string clave_ingresado);
string verificar_saldo(string saldo);
string retirar_saldo(string saldo);
string modificar(string archivo,string ced, string clave, string saldo);

void modificar_archivos(string open_usr, string nombre, string clave,string saldo2);





#endif //ARCHIVOS_H