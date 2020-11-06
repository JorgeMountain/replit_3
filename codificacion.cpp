#include "codificacion.h"
using namespace std;

string codificacion(string name,int method, int n){

  string  bina_codi;
  if (method==1){
      bina_codi= Metodo1_particion(name, n);

  }
  else{
   bina_codi= metodo2( name, n);
  }
  return bina_codi;
}

string decodificacion(string name,int method, int n){
  string bina_codi;

  if (method==1){
      bina_codi= Metodo1_particion_deco( name, n);

  }
  else{
   bina_codi= metodo2_deco( name, n);
  }
  return bina_codi;
}

string text2bin(string texto){
  string binario;
  for (unsigned long long int i=0;i<texto.length();i++){
    for (int j=0;j<8;j++){
      binario.push_back(char(((texto[i]<<j)&(0x80))/128+48));
    }
  }
  return binario;
}

string bin2text(string binario){
    string texto;
    int  multiplicador=1,decimal=0, bina=8,k=0 ;
    for (unsigned long long int i=0;i<binario.length();i++){
      decimal=0;
      for (int i = bina - 1; i >= k; i--) {
            if (binario[i] == '1') {
                decimal += multiplicador;
            }
            multiplicador = multiplicador * 2;
        }
        texto+=decimal;
        k+=8;
        i+=7;
        bina+=8;
        multiplicador =1;
    }
    return texto;
    
}
    

string Metodo1_particion(string binario, int n){
  string partido, copia, codificado;
  for (unsigned long long int i=0, k=0;i<binario.length();i++){
        partido.push_back(binario[i]);
        if (k<1){
            if (binario[i]==49) codificado.push_back(48);
            else codificado.push_back(49);
            if (n-1==i){
                copia=partido;
                partido.clear();
                k++;
            }
        }
        else{
            if ((k+1)*n-1==i){
              codificado=codificado + codificar_grupo(partido,copia);
              copia=partido;
              partido.clear();
              k++;
            }
        }

  }
return codificado;
}


string Metodo1_particion_deco(string binario, int n){
  string partido, copia, decodificado;
    for (unsigned long long int i=0, k=0;i<binario.length();i++){
        partido.push_back(binario[i]);
        if (k<1){
            if (binario[i]==49) decodificado.push_back(48);
            else decodificado.push_back(49);
            if (n-1==i){
                copia=decodificado;
                partido.clear();
                k++;
            }
            else if (i==binario.length()-1){
            copia=codificar_grupo(partido, copia);
            decodificado=decodificado +copia;           
            }
        }
        else{
             if ((k+1)*n-1==i){
                  copia= codificar_grupo(partido,copia);
                  decodificado=decodificado+copia;
                  partido.clear();
                  k++;
                }
        }
        
  }
  return decodificado;
}


string codificar_grupo(string partido, string copia ){
    long int  uno=0,cero=0;
    for (unsigned long long int i=0;i<partido.length();i++){
        if (copia[i]==49){
          uno++;
        } 
        else {
          cero++;
        }
    }
    if (uno==cero){
        for(unsigned int i=0;i<partido.length();i++){
            if(partido[i]==49) partido[i]=48;
            else partido[i]=49;
        }
    }
    else if(cero>uno){
        for (unsigned int i=1;i<partido.length();i+=2){
            if(partido[i]==49) partido[i]=48;
            else partido[i]=49;
        }
    }
    else{
        for (unsigned int i=2;i<partido.length();i+=3){
            if(partido[i]==49) partido[i]=48;
            else partido[i]=49;
        }
    }
    return partido;
}




string metodo2(string binario,int n){
 string archivo, copia;
        unsigned int k=0;

        for(unsigned long long int i=0;i<binario.length();i++){
            copia.push_back(binario[i]);
            if (i==(k+1)*n-1){
                archivo+= cambio_posicion(copia);
                copia.clear();
                k++;
            }
            else if (i==binario.length()-1){
                archivo+= cambio_posicion(copia);
            }
        }
        return archivo;
 }


string cambio_posicion(string binario){
    unsigned int i;
    string bina2, copia;
    copia=binario[binario.length()-1];
    for (i=0;i<binario.length();i++){
        bina2+=copia;
        copia=binario[i];
    }
    return bina2;
}



string metodo2_deco(string binario,int n){
 string archivo, copia;
        unsigned int k=0;
        for(unsigned long long int i=0;i<binario.length();i++){
            copia.push_back(binario[i]);
            if (i==(k+1)*n-1){
                archivo+= cambio_posicion_deco(copia);
                copia.clear();
                k++;
            }
            else if (i==binario.length()-1){
                archivo+= cambio_posicion_deco(copia);
            }
        }
        return archivo;
 }


string cambio_posicion_deco(string binario){
    unsigned int i;
    string bina2, copia;
    for (i=1;i<=binario.length();i++){
        if (i==binario.length()) bina2+=binario[0];
        else bina2+=binario[i];
    }
    return bina2;
}


string codifi(string archivo, int metodo, int n){
  string open_admin_usr;
  open_admin_usr = leer_txt(archivo);
  open_admin_usr = text2bin(open_admin_usr);
  open_admin_usr= codificacion(open_admin_usr,metodo, n);
  open_admin_usr = bin2text(open_admin_usr);
  return open_admin_usr;
}


string decodifi(string archivo, int metodo, int n){
  string open_admin;
  open_admin = text2bin(archivo);
  open_admin= decodificacion(open_admin,metodo, n);
  open_admin = bin2text(open_admin);  
  return open_admin;
}


