#include "Archivos.h"

void escribir_txt(string name, string data){
  fstream k(name, fstream::out | fstream::binary);
  //k<<data
  k.write(data.c_str(), data.length());
  k.close();
}


string leer_txt(string name){
  long long int tam;
  string data;
  fstream k(name, fstream::in | fstream::ate | fstream::binary);  
  if(k.is_open()){
    tam=k.tellg();
    k.seekg(0);
    for(long long int i=0;i<tam; i++) data.push_back(k.get()); 
  }
  else cout<<"El archivo de texto no existe"<<endl;
  k.close();
  return data; 
}

bool verificar_admin(string archivo, string clave_ingresado){
    string clave_confirmar;
    bool valid=false;

    for (unsigned int i=0; i<archivo.length(); i++){
      for (;archivo[i] != '\n';i++){
        clave_confirmar.push_back(archivo[i]);
      }
    }
  if (clave_confirmar==clave_ingresado){
        cout << "Bienvenido, administrador" << endl;
        valid=true;
      }
      else{
        clave_confirmar.clear();
      }
      return valid;
    }



string modificar_archivos(string archivo,string cedula, string clave, string saldo2){
    string clave_ori, cedula_ori, archivo_new, saldo;

    for (unsigned int i=0; i<archivo.length(); i++){
      for (;archivo[i]!=',';i++){
        cedula_ori.push_back(archivo[i]);
      }
      for (i++;archivo[i] !=',';i++){
        clave_ori.push_back(archivo[i]);
      }
      for (i++;archivo[i] !='\n';i++){
        saldo.push_back(archivo[i]);
      }

      if (cedula==clave_ori && clave==clave_ori){
        archivo_new = archivo_new + cedula + "," + clave + "," + saldo2 + "\n";
          clave_ori.clear();
          cedula_ori.clear();
          saldo.clear();
      }
      else{
          archivo_new = archivo_new + cedula_ori + "," + clave_ori + "," + saldo + "\n";
          clave_ori.clear();
          cedula_ori.clear();
          saldo.clear();
      }
      
     }
     return archivo_new;
 }


string verificar_saldo(string saldo){
    cout << "Descontamos 1000$ de su saldo activo por la revision"<< endl; 
    long int saldoint;
    saldoint=atoi(saldo.c_str());
    saldoint -= 1000;
    cout << "Su saldo es de: " << saldoint << endl;
    saldo = to_string(saldoint);
    return saldo;
}

string retirar_saldo(string saldo){
    cout << "Descontamos 1000$ de su saldo activo por el retiro"<< endl; 
    ifstream leer;
    ofstream guardar;
    guardar.open("InfoUsr.txt",ios::app);
    long int saldoint, retiro;
    saldoint=atoi(saldo.c_str());
    saldoint = saldoint - 1000;
    cout << "Su saldo es de: " << saldoint << endl;
    cout<<"Ingrese la cantidad de dinero que desea retirar"<<endl;
    cin >>retiro;
    while (retiro < 1){
      cout<<"No puede retirar una cantidad negativa"<<endl;
      cout<<"Ingrese la cantidad de dinero que desea retirar"<<endl;
      cin >>retiro;
        }
    while (retiro > saldoint-1000){
      cout<<"La cantidad ingresada es mayor a su saldo"<<endl;
      cout<<"Ingrese la cantidad de dinero que desea retirar"<<endl;
      cin >>retiro;
        }
    saldoint = saldoint - retiro;
    saldo = to_string(saldoint);
    return saldo;
}



