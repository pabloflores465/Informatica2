#include <iostream>
#include <string>


using namespace std;

int main() {

    //NO TOCAR Seleccion de los modulos
    int modulos;

    //Arrelos para la descripcion de los farmacos
    //Modulo 1
    //Tipos de Farmacos
    string nombrefarmacos[10]{"Ibuprofeno 100mg","Nauseol 50mg","PEPTO-BISMOL Cereza 236ml","VICK BEBE BALSAMO 50 GRS","TABCIN GRIPE Y TOS LIQUI-GELS","VITAMINA C 500 MG","AZITROMICINA 500MG","ASPIRINA ADULTOS 500 MG","BRONCUROL","DOLO TRIVIPLEX INYECTADO",};

    //Modulo 1
    //Descripcion de Medicamentos
    string descripcionfarmacos[10]{"Antiinflamatorio","Medicamento para eliminar la naúseas, mareos y vómitos","Medicamento usado para el tratamiento de la indigestión, el malestar estomacal, la diarrea","Descongestion nasal","Medicamento para aliviar la tos y la gripe","Fortalece las defensas del organismo y ayuda a la cicatrizacion","Antibiotico de amplio espectro","Medicamento para tratar el dolor, la fiebre y la inflamación","Medicamento para aliviar la tos y el resfriado","Medicamento para aliviar dolores neuriticos"};

    //Modulo 1
    //Presentacion del Farmaco
    //// Esta parte que ma volé ya que en la parte del tamaño de farmaco se indica cual es su presentacion.


    //Modulo 1
    //Tamaño del farmaco
    string cantidadfarmacos[10]{"100 tabletas","2 ampollas","ml ","ml","12 tabletas","20 tabletas","12 tabletas","100 tabletas","100 comprimidos","2 ampollas",};

    //Modulo 1
    //Precio de los farmacos
    //Cambié los arreglos para que queden en una misma linea para que así el codigo tenga menos lineas y se vea mas limpio.
    float preciofarmacos[10]{186.95,26.00,64.99,33.02,26.95,28.20,559.98,96.76,104.75,50.38};

    //Modulo 1
    //Existencias de los farmacos
    double existenciasfarmacos[10]{20,20,20,20,20,20,20,20,20,20
    };

    //Modulo 2
    //Aseguradoras Usadas
    string aseguradora[5]{"Seguros GyT","Seguro Agromercantil","Aseguradora General, S.A.","Seguros El Roble","Mapfre"};
    //Modulo 2
    //Taza de descuento fija
    float tazaDescuento[5]{0.25,0.60,0.40,0.5,0.75,};
    // Movi esto hacia para aca arriba para poder llamar esto en mi modulo 3
    string titulartarjeta,fechavencimiento,codigotarjeta,numerotarjeta;
    float suma=0.0;
    int seguro=0;
    int descuentoseguro;
    int lola=0;
    string nombre[200];
    string usuario, contraseña;

    cout << "Ingrese el usuario: ";
    cin >> usuario;
    cout << "Ingrese la contraseña: ";
    cin >> contraseña;
    if (usuario == "Admin" && contraseña == "Contra");
        else {
            cout << "Usuario incorrecto";
        }

    do {
        cout << "Para modulo de farmacia presione 1\n";
        cout << "Para modulo de seguros presione 2\n";
        cout << "Para modulo de reportes presione 3\n";
        cout << "Ingrese el numero 4 para finalizar el proceso\n";
        cout<<"Escriba aqui el modulo al que quiere acceder\n";
        cin >> modulos;
        switch (modulos) {
            case 1: {
                int modulo1;
                int i=0;
                int ii=0;

                cout<<"Este modulo es para comprar productos, para salir de este modulo presione (0)\n"<<endl;

                cout<<"Los productos que usted puede elegir son los siguientes: \n";

                //Se le da informacion al usuario acerca de los farmaco
                //Numero de Producto
                //Precio
                //Descripcion
                //Las Existencias

                //Producto1
                cout<<"Presione (1) para elegir "<<nombrefarmacos[0]<<"\n"
                    <<"Precio: Q"<<preciofarmacos[0]<<"\n"
                    <<"Descripcion: "<<descripcionfarmacos[0]<<" "<<"("<<cantidadfarmacos[0]<<")"<<"\n"
                    <<"Las existencias de este producto son: "<<existenciasfarmacos [0]<<"\n\n";

                //Producto 2
                cout<<"Presione (2) para elegir "<<nombrefarmacos[1]<<"\n"
                    <<"Precio: Q"<<preciofarmacos[1]<<"\n"
                    <<"Descripcion: "<<descripcionfarmacos[1]<<" "<<"("<<cantidadfarmacos[1]<<")"<<"\n"
                    <<"Las existencias de este producto son: "<<existenciasfarmacos [1]<<"\n\n";

                //Producto 3
                cout<<"Presione (3) para elegir "<<nombrefarmacos[2]<<"\n"
                    <<"Precio: Q"<<preciofarmacos[2]<<" "<<"\n"
                    <<"Descripcion: "<<descripcionfarmacos[2]<<" "<<"("<<cantidadfarmacos[2]<<")"<<"\n"
                    <<"Las existencias de este producto son: "<<existenciasfarmacos [2]<<"\n\n";

                //Producto 4
                cout<<"Presione (4) para elegir "<<nombrefarmacos[3]<<"\n"
                    <<"Precio: Q"<<preciofarmacos[3]<<"\n"
                    <<"Descripcion: "<<descripcionfarmacos[3]<<" "<<"("<<cantidadfarmacos[3]<<")"<<"\n"
                    <<"Las existencias de este producto son: "<<existenciasfarmacos [3]<<"\n\n";

                //Producto 5
                cout<<"Presione (5) para elegir "<<nombrefarmacos[4]<<"\n"
                    <<"Precio: Q"<<preciofarmacos[4]<<"\n"
                    <<"Descripcion: "<<descripcionfarmacos[4]<<" "<<"("<<cantidadfarmacos[4]<<")"<<"\n"
                    <<"Las existencias de este producto son: "<<existenciasfarmacos [4]<<"\n\n";

                //Producto 6
                cout<<"Presione (6) para elegir "<<nombrefarmacos[5]<<"\n"
                    <<"Precio: Q"<<preciofarmacos[5]<<"\n"
                    <<"Descripcion: "<<descripcionfarmacos[5]<<" "<<"("<<cantidadfarmacos[5]<<")"<<"\n"
                    <<"Las existencias de este producto son: "<<existenciasfarmacos [5]<<"\n\n";

                //Producto 7
                cout<<"Presione (7) para elegir "<<nombrefarmacos[6]<<"\n"
                    <<"Precio: Q"<<preciofarmacos[6]<<"\n"
                    <<"Descripcion: "<<descripcionfarmacos[6]<<" "<<"("<<cantidadfarmacos[6]<<")"<<"\n"
                    <<"Las existencias de este producto son: "<<existenciasfarmacos [6]<<"\n\n";

                //Producto 8
                cout<<"Presione (8) para elegir "<<nombrefarmacos[7]<<"\n"
                    <<"Precio: Q"<<preciofarmacos[7]<<"\n"
                    <<"Descripcion: "<<descripcionfarmacos[6]<<" "<<"("<<cantidadfarmacos[7]<<")"<<"\n"
                    <<"Las existencias de este producto son: "<<existenciasfarmacos [7]<<"\n\n";

                //Producto 9
                cout<<"Presione (9) para elegir "<<nombrefarmacos[8]<<"\n"
                    <<"Precio: Q"<<preciofarmacos[8]<<"\n"
                    <<"Descripcion: "<<descripcionfarmacos[8]<<" "<<"("<<cantidadfarmacos[8]<<")"<<"\n"
                    <<"Las existencias de este producto son: "<<existenciasfarmacos [8]<<"\n\n";

                //Producto 10
                cout<<"Presione (10) para elegir "<<nombrefarmacos[9]<<"\n"
                    <<"Precio: Q"<<preciofarmacos[9]<<"\n"
                    <<"Descripcion: "<<descripcionfarmacos[9]<<" "<<"("<<cantidadfarmacos[9]<<")"<<"\n"
                    <<"Las existencias de este producto son: "<<existenciasfarmacos [9]<<"\n\n";

                do{
                    cout<<"Escriba aqui el numero del medicamento que quiere elegir";
                    if (i!=0)
                    {
                        cout<<" o si ya no deseas seguir comprando un producto presiona 0\n";
                    }
                    else
                    {
                        cout<<"\n";
                    }
                    i++;
                    cin>>modulo1;
                    switch (modulo1)
                    {
                        case 0:
                        {
                            cout<<"\n";
                            break;
                        }
                        case 1:
                        {
                            suma=suma+preciofarmacos[0];
                            existenciasfarmacos [0]--;
                            ii++;
                            break;

                        }
                        case 2:
                        {
                            suma=suma+preciofarmacos[1];
                            existenciasfarmacos [1]--;
                            ii++;
                            break;
                        }
                        case 3:
                        {
                            suma=suma+preciofarmacos[2];
                            existenciasfarmacos [2]--;
                            ii++;
                            break;
                        }
                        case 4:
                        {
                            suma=suma+preciofarmacos[3];
                            existenciasfarmacos [3]--;
                            ii++;
                            break;
                        }
                        case 5:
                        {
                            suma=suma+preciofarmacos[4];
                            existenciasfarmacos [4]--;
                            ii++;
                            break;
                        }
                        case 6:
                        {
                            suma=suma+preciofarmacos[5];
                            existenciasfarmacos [5]--;
                            ii++;
                            break;
                        }
                        case 7:
                        {
                            suma=suma+preciofarmacos[6];
                            existenciasfarmacos [6]--;
                            ii++;
                            break;
                        }
                        case 8:
                        {
                            suma=suma+preciofarmacos[7];
                            existenciasfarmacos [7]--;
                            ii++;
                            break;
                        }
                        case 9:
                        {
                            suma=suma+preciofarmacos[8];
                            existenciasfarmacos [8]--;
                            ii++;
                            break;
                        }
                        case 10:
                        {
                            suma=suma+preciofarmacos[9];
                            existenciasfarmacos [9]--;
                            ii++;
                            break;
                        }
                    }
                }
                while(modulo1!=0);
                cout<<"\n";
                cout<<"El total a pagar es de "<<"Q"<<suma<<"\n"
                    <<"El total de productos que usted comprara es de "<<ii<<"\n\n";

                if(ii!=0) {
                    cout<<"¿Usted cuenta con alguno de los siguientes seguro?\n"
                        <<"Presione 1 para si y 0 para no\n";
                    cin>>descuentoseguro;
                    //AQUI SEÑORES
                    if (descuentoseguro==1)
                    {
                        int dess;
                        float descuentoaplicado=0;
                        cout<<"Ingrese el seguro con el que usted cuenta\n";
                        cout<<"1=Seguros GyT\n"
                            <<"2=Seguro Agromercantil\n"
                            <<"3=Aseguradora General, S.A.\n"
                            <<"4=Seguros el Roble\n"
                            <<"5=Mapfre\n";
                        cin>>dess;
                        switch (dess)
                        {
                            case 1:
                            {
                                descuentoaplicado=suma*0.75;
                                break;
                            }
                            case 2:
                            {
                                descuentoaplicado=suma*0.40;
                                break;
                            }
                            case 3:
                            {
                                descuentoaplicado=suma*0.60;
                                break;
                            }
                            case 4:
                            {
                                descuentoaplicado=suma*0.5;
                                break;
                            }
                            case 5:
                            {
                                descuentoaplicado=suma*0.25;
                                break;
                            }
                        }
                        cout<<"El nuevo total a pagar con el descuento aplicado es de "<<descuentoaplicado<<"\n";
                    }
                    else {
                        cout<<"usted no cuenta con un seguro\n";
                    }
                    cout<<"Ingrese la información de la tarjeta para pagar:\n\n"
                        <<"Ingrese el nombre del titular de la tarjeta:\n";
                    cin>>nombre[lola];
                    lola++;
                    cout<<"\n"
                        <<"Ingre se la fecha de vencimiento de la tarjeta, ejemplo:4/23\n";
                    cin>>fechavencimiento;
                    cout<<"\n"
                        <<"Ingrese el numero de su tarjeta, ejemplo 123456789\n";
                    cin>>numerotarjeta;
                    cout<<"\n"
                        <<"Ingrese el codigo de su tarjeta, ejemplo 456\n";
                    cin>>codigotarjeta;
                    cout<<"\n\n"
                        <<"PAGO EXITOSO\n\n";
                }
                break;
            }
            case 2: {
                //Inicia el Modulo 2
                //Variable que selecciona el seguro

                //Pido al usuario que ingrese el seguro
                cout<<"Módulo de Seguros"<<endl;
                cout<<"Para ver información de copagos (descuento sobre medicinas), por favor elija su aseguradora (ingrese un dígito)"<<endl;
                cout<<"0=Seguros GyT\n"
                    <<"1=Seguro Agromercantil\n"
                    <<"2=Aseguradora General, S.A.\n"
                    <<"3=Seguros el Roble\n"
                    <<"4=Mapfre\n";
                    cin>>seguro;
                //Aqui se Muestra la informacion de la aseguradora seleccionada
                switch(seguro) {
                    //Seguros GyT
                    case 0: {
                        cout << aseguradora[seguro] << endl;
                        cout << "Su copago es: \n"
                             << (tazaDescuento[seguro]) * 100 << "%" << endl;
                        break;
                    }
                        //Seguro Agromercantil |
                    case 1: {
                        cout << aseguradora[seguro] << endl;
                        cout << "Su copago es: \n"
                             << (tazaDescuento[seguro]) * 100 << "%" << endl;
                        break;
                    }
                        //Aseguradora General, S.A.
                    case 2: {
                        cout << aseguradora[seguro] << endl;
                        cout << "Su copago es: \n"
                             << (tazaDescuento[seguro]) * 100 << "%" << endl;
                        break;
                    }
                        //Seguros El Roble
                    case 3: {
                        cout << aseguradora[seguro] << endl;
                        cout << "Su copago es: \n"
                             << (tazaDescuento[seguro]) * 100 << "%" << endl;
                        break;
                    }
                        //Mapfre
                    case 4: {
                        cout << aseguradora[seguro] << endl;
                        cout << "Su copago es: \n"
                             << (tazaDescuento[seguro]) * 100 << "%" << endl;
                        break;
                    }
                        //Mensaje de Error
                    default: {
                        cout << "Error no se seleccionó un valor válido" << endl;
                        break;
                    }
                }
                break;
            }
            case 3: {
                // Puse esta variable local "info" para que el admin decida que tipo de informacion desplegar
                int info;
                cout << "Ingrese el tipo de información que desea ver" << "\n";
                cout << "Ingrese 1 para desplegar la informacion de la famacia \n";
                cout << "Ingrese 2 para desplegar la información de las aseguradoras \n";
                cin >> info;
                switch (info)
                {
                    case 1:
                        cout<<"Resumen del día \n";
                        cout << "Inventario de medicamentos:  \n";
                        cout << nombrefarmacos[0] << " " << existenciasfarmacos [0]  <<  "\n" ;
                        cout << nombrefarmacos[1] << " " <<  existenciasfarmacos [1]  <<  "\n" ;
                        cout << nombrefarmacos[2] << " " <<  existenciasfarmacos [2]  <<  "\n" ;
                        cout << nombrefarmacos[3] << " " <<  existenciasfarmacos [3]  <<  "\n" ;
                        cout << nombrefarmacos[4] << " " <<  existenciasfarmacos [4]  <<  "\n" ;
                        cout << nombrefarmacos[5] << " " <<  existenciasfarmacos [5]  <<  "\n" ;
                        cout << nombrefarmacos[6] << " " <<  existenciasfarmacos [6]  <<  "\n" ;
                        cout << nombrefarmacos[7] << " " <<  existenciasfarmacos [7]  <<  "\n" ;
                        cout << nombrefarmacos[8] << " " <<  existenciasfarmacos [8]  <<  "\n" ;
                        cout << nombrefarmacos[9] << " " <<  existenciasfarmacos [9]  <<  "\n" ;
                        cout << "\n";
                        cout << "Total de medicamentos vendidos: \n" << endl ;
                        cout << "\n";
                        cout << "Total de clientes que compraron el día de hoy: \n";
                        for (int i = 0; i < lola ; ++i) {
                            cout<<nombre[i]<<endl;
                        }
                        cout << "Total de ventas: \n";
                        cout << suma << "\n";
                        break;
                    case 2:
                        cout << "Informacion de las aseguradoras \n ";
                        cout << "Los clientes que han utilizado su seguro en esta farmacia son: \n";
                        if (descuentoseguro=1)
                            cout << titulartarjeta ;
                        cout << "\n";
                        cout << "El seguro mas usado es: \n";
                        cout << "insertar el seguro \n";
                }
                break;
            }
            default: {
                cout << "Error ingrese un numero valido\n\n";
                break;
            }
        }
    }
    while (modulos != 4);

    return 0;
}

