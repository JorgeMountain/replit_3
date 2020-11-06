#include "Archivos.h"

void cajero(string archivo_admin,string archivo_usr, int metodo, int n){
      string clave_admin, clave_usr, ced_usr;
      string open_admin, open_usr;
      open_admin = leer_txt(archivo_admin);
      open_usr= leer_txt(archivo_usr);
      string archivo;
      int usr=0, Nsaldo;
      bool ban=true;
      while (ban==true){

          cout << "Bienvenido, porfavor ingrese el tipo de usuario "<< endl;
          cout << " ------------------ "<< endl;
          cout << "|    Usuario    (1) |"<< endl;
          cout << "| Adminitrador  (2) |"<< endl;
          cout << "|     Salir     (3) |"<< endl;
          cout << " ------------------ "<< endl;
          cin >> usr;
          system("CLS");
          while (usr!=1 && usr!=2 && usr!=3){
            cin >> usr;
          }

          switch(usr){
            
            case 1:{
              string datos_usr;
              string cedula, clave, saldo, saldo2;
              bool veri_usr=false;
              bool usr = true;
              while (usr==true){
                  cout<<"Ingrese su cedula : "<<endl;
                  cin >> ced_usr;
                  cout<<"ingrese su clave : "<<endl;
                  cin>>clave_usr;
                while (veri_usr==false){                        
                    for (unsigned int i=0; i<open_usr.length(); i++){
                        for (;open_usr[i]!=44;i++){
                          cedula.push_back(open_usr[i]);
                        }
                        for (i++;open_usr[i] !=44;i++){   
                          clave.push_back(open_usr[i]);
                        }
                        for (i++;open_usr[i] !='\n';i++){
                          saldo.push_back(open_usr[i]);
                        }
                        if (cedula==ced_usr && clave==clave_usr){
                          cout << "Bienvenido" << endl;
                          veri_usr=true;
                          break;
                        } 
                        else{
                          clave.clear();
                          cedula.clear();
                        }
                    }
               }

                while (usr==true){
                  
                  cout << " ---------------------- "<< endl;
                  cout << "|      Bienvenido      |"<< endl;
                  cout << "|   Que desea hacer?   |"<< endl;
                  cout << " ---------------------- "<< endl;
                  cout << "| Consultar saldo  (1) |"<< endl;
                  cout << "| Retirar dinero   (2) |"<< endl;
                  cout << "| Salir del menu   (3) |"<< endl;
                  cout << " ---------------------- "<< endl;
                  cin >> n;
                  system("CLS");

                  if (n==1){
                    saldo2=verificar_saldo(saldo);
                    modificar_archivos(open_usr,cedula, clave, saldo2);
                  }
                  else if(n==2){
                   saldo2=retirar_saldo(saldo);
                   cout<<saldo2;
                   modificar_archivos(open_usr,cedula, clave, saldo2);

                  }
                 else if (n==3){
                   usr=false;
                   break;
                 }
                }
              
            }}
            break;
            case 2:{
              string datos_usr;
              bool adm=true;
              bool veri_adm= false;
              while (adm==true){
                  while (veri_adm==false){
                    cout<<"Ingrese la clave administrador o x para salir"<<endl;
                    cin >> clave_admin;
                    if (clave_admin=="x"){
                      veri_adm=true;
                      adm=false;
                      break;
                    }
                    else{
                      veri_adm=verificar_admin(open_admin,clave_admin);
                    }
                  }
                if (adm==true){
                    system("CLS");
                    cout << " ---------------------- "<< endl;
                    cout << "|      Bienvenido      |"<< endl;
                    cout << "|   Que desea hacer?   |"<< endl;
                    cout << " ---------------------- "<< endl;
                    cout << "| Crear usuario    (1) |"<< endl;
                    cout << "| Salir del menu   (2) |"<< endl;
                    cout << " ---------------------- "<< endl;
                    cin>>n;
                    system("CLS");

                    //Cedula
                    if (n==1){
                      bool flagced=false;
                      while (flagced==false){
                            string linea;
                            long int cedint=0, claveint=0, saldoint=0;
                            string cedula_copia;
                            string clave,saldo,ced;
                            cout << "Ingresar nueva cedula"<< endl;
                            cout << "Cedula #: ";
                            cin >> ced;
                            cedint=atoi(ced.c_str());
                            while (cedint < 1 ){
                                cout << "[ERROR] Ingrese una cedula admisible"<< endl;                   
                                cout << "Cedula #: ";
                                cin >> ced;
                                cedint=atoi(ced.c_str());
                            }
                            ced = to_string(cedint);
                            
                            //Clave
                            cout <<endl<< "Ingresar la clave"<< endl;
                            cout << "Clave: ";
                            cin >> clave;
                            claveint=atoi(clave.c_str());
                            while (claveint < 1){
                                cout << "[ERROR] Ingrese una clave admisible"<< endl;
                                cout << "Clave: ";
                                cin >> clave;
                                claveint=atoi(clave.c_str());
                            }
                            clave = to_string(claveint);
                            //Saldo
                            cout << endl<<"Ingresar el saldo"<< endl;
                            cout << "Saldo: ";
                            cin >> saldo;
                            saldoint=atoi(saldo.c_str());
                            while (saldoint < 1000){
                                cout << "[ERROR] Ingrese un valor de saldo admisible mayor a 1000"<< endl;
                                cout << "Saldo: ";
                                cin >> saldo;
                                saldoint=atoi(saldo.c_str());
                            }
                            saldo = to_string(saldoint);
                            cout << "entro a saldo"<< endl;
                            datos_usr= ced+ "," + clave + "," + saldo;
                            ofstream guardar;             
                            guardar.open("InfoUsr.txt",ios::app);
                            guardar <<datos_usr<<endl;
                            cout << "Agregando nuevo usuario...";
                            system("CLS");
                            flagced=true;
                            break;
                          
                              
                        }
                     }

                    
                    else if (n==2) {adm=false;}
                }
                }
      
            } 
            break;    
            case 3:{
              ban=false;
                  break;
            }
            break;
            default:
                cout << "Esta opcion no esta definida "<< endl;
            break;
          }
          
      }
  }