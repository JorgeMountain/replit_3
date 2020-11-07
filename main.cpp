#include "codificacion.h"

int main() {
  
  string archivo_admin= "clave_admin.txt";
  string archivo_usr= "InfoUsr.txt";
  string archivo_prueba= "ensayo.txt";
  //string archivo_prueba= "M1S6 .dat";
  int metodo, n;
  cout<<"Ingrese el metodo de codificacion deseado y la semilla  n: ";
  cin>> metodo>> n;
  PruebasMetodo(archivo_prueba, metodo, n);
  cajero(archivo_admin, archivo_usr, metodo, n);
  
  return 0;
}



