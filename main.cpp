#include <iostream>
#include <string>
#include "algorithm"
#include<tuple>
#include <map>
#include <climits>
using namespace std;

//NO TOCAR Seleccion de los modulos
int modulo;

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
double existenciasfarmacos[10]{20,20,20,20,20,20,20,20,20,20};


//Modulo 2
//Aseguradoras Usadas
string aseguradora[5]{"Seguros GyT","Seguro Agromercantil","Aseguradora General, S.A.","Seguros El Roble","Mapfre"};
// Contadores para las aseguradoras
int gyt;
int agro, gene, robl, mapf;

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

//Modulo 4
//Contador
int contador=0;
//Nombre de usuario
string usuario[200];
//Nombre de la persona
string name[200];
//Apellido de la Persona
string lastName[200];
//Rol del Usuario
int rol[200];
//Contraseña del Usuario
string password[200];
//El usuario esta bloqueado?
int bloqueado[200];

// El contador de los productos que llevan
int ii;
float sumacl=0.0;

//Main

//Declaracion de las funciones

//Modulo1
void modulo1();

//Modulo2
void modulo2();

//Modulo3
void modulo3();

//Modulo4
void modulo4();

//Messaeje de error
void mensajeError();


int main() {
    //Este es el rol que el usuario ingresa
    int rolIngresado=0;
    //Este es un contador general
    int contadorGeneral;
    //Se usa para verificar que sea
    int dependiente;
    //Se usa para verificar que sea un cliente
    int administrador;
    //No. de Intentos restantes
    int intentos=0;
    //Este es el usuario del Administrador
    string nombreADMIN;
    //Esta es la contraseña del Administrador
    string contraADMIN;
    //Este es el usuario del Cliente
    string nombreCliente;
    //Esta es la contraseña del Cliente
    string contraCliente;
    //Este es el usuario del Dependiente
    string nombreDep;
    //Esta es la contraseña del Cliente
    string contraDep;

   cout<<"Hola administrador\n"<<
        "Por favor realiza la configuración inicial de los usuarios."<<endl;
   do{
        //Ingresan el usuario
        cout<<"Usuario"<<endl;
        cin>>nombreADMIN;
        //Ingresan la contraseña
        cout<<"Contraseña"<<endl;
        cin>>contraADMIN;
        if (nombreADMIN=="ADMIN"&&contraADMIN=="admin"){
            modulo4();
        }
        else {
            cout<<"ERROR: Usuario o Contraseña de administrador incorrectos"<<endl;
        }
    }
    while (nombreADMIN!="ADMIN"||contraADMIN!="admin");

    do{
        cout<<"Bienvenido a Farmacias Batres"<<endl;
        cout<<"¿Quien es usted?\n"
            <<"1=Cliente\n"
            <<"2=Empleado\n"
            <<"3=Otro\n";
        cin>>rolIngresado;
        if (rolIngresado==1){

            cout<<"Usuario"<<endl;
            cin>>nombreCliente;
            contadorGeneral=0;
            while(contadorGeneral<200&&nombreCliente!=usuario[contadorGeneral]&&bloqueado[contadorGeneral]!=1){
                contadorGeneral++;
            }

            if (contadorGeneral<200&&nombreCliente==usuario[contadorGeneral]&&rol[contadorGeneral]==0&&bloqueado[contadorGeneral]==0) {
                //Ingresan la contraseña

                if (bloqueado[contadorGeneral]!=1) {
                    cout << "Contraseña" << endl;
                    cin >> contraCliente;
                }

                if (contraCliente == password[contadorGeneral]) {

                    do {
                        cout << "¿A que modulo quieres ingresar?\n"
                             << "1=Farmacias\n"
                             << "2=Seguros\n"
                             << "0=Cerrar Sesión\n"
                             << endl;
                        cin >> modulo;
                        switch (modulo) {
                            case 0:{
                                cout<<"Sesion cerrada con éxito"<<endl;
                                break;
                            }
                            case 1: {
                                modulo1();
                                break;
                            }
                            case 2: {
                                modulo2();
                                break;
                            }
                            default: {
                                cout << "Error valor no valido" << endl;
                                break;
                            }
                        }
                    }
                    while (modulo!=0);

                }
                else {
                    cout<<"Contraseña incorrecta"<<endl;
                    intentos++;
                }
                if(intentos>3){
                    bloqueado[contadorGeneral]=1;
                    cout<<"Error el usuario se bloqueo por el uso de demasiados intentos"<<endl;
                }

            }
            else {
                cout<<"Usuario no encotrado, por ingreselo de nuevo"<<endl;
            }

        }
        else if (rolIngresado==2){
            //Ingresan el usuario
            cout<<"Usuario"<<endl;
            cin>>nombreDep;

            //Ingresan la contraseña
            cout<<"Contraseña"<<endl;
            cin>>contraDep;

            contadorGeneral=0;
            while (contadorGeneral<200){
                if (nombreDep==usuario[contadorGeneral]&&contraDep==password[contadorGeneral]&&rol[contadorGeneral]==1){
                    dependiente=1;
                }
                contadorGeneral++;
            }
            if (dependiente==1){
                do{
                    cout<<"¿A que modulo quieres ingresar?\n"
                        <<"1=Farmacias\n"
                        <<"2=Seguros\n"
                        <<"3=Reportes\n"
                        <<"0=Cerrar Sesión\n"
                        <<endl;
                    cin>>modulo;
                    switch (modulo) {
                        case 0:{
                            cout<<"Sesión cerrada con éxito"<<endl;
                            break;
                        }
                        case 1:{
                            modulo1();
                            break;
                        }
                        case 2:{
                            modulo2();
                            break;
                        }
                        case 3:{
                            modulo3();
                            break;
                        }
                        default:{
                            cout<<"Error valor no valido"<<endl;
                            break;
                        }
                    }
                }
                while (modulo!=0);
            }
            else {
               cout<<"Empleado no econtrado, por favor pruebe de nuevo"<<endl;
            }
        }
        else if (rolIngresado==3){
            //Ingresan el usuario
            cout<<"Usuario"<<endl;
            cin>>nombreADMIN;
            //Ingresan la contraseña
            cout<<"Contraseña"<<endl;
            cin>>contraADMIN;
            contadorGeneral=0;
            while (contadorGeneral<200){
                if (nombreADMIN=="ADMIN"&&contraADMIN=="admin"){
                    administrador=1;
                }
                contadorGeneral++;
            }
            if (administrador==1){
                do {
                    cout<<"¿A que modulo quieres ingresar?\n"
                        <<"1=Farmacias\n"
                        <<"2=Seguros\n"
                        <<"3=Reportes\n"
                        <<"4=Administrar\n"
                        <<"0=Cerrar Sesión\n"
                        <<endl;
                    cin>>modulo;
                    switch (modulo) {
                        case 0:{
                            cout<<"Sesión cerrada con éxito"<<endl;
                            break;
                        }
                        case 1:{
                            modulo1();
                            break;
                        }
                        case 2:{
                            modulo2();
                            break;
                        }
                        case 3:{
                            modulo3();
                        }
                        case 4:{
                            modulo4();
                            break;
                        }
                        default:{
                            cout<<"Error valor no valido"<<endl;
                            break;
                        }
                    }
                }
                while (modulo!=0);
            }
            else {
                cout<<"Usuario administrador incorrecto,por favor pruebe de nuevo"<<endl;
            }
        }
    }
    while(rolIngresado!=0);

    return 0;
}

void modulo1(){
    int modulo1;
    int i=0;

    cout<<"Este modulo es para comprar productos, para salir de este modulo presione (0)\n"<<endl;
    cout<<"El máximo de medicamentos que se pueden comprar es de 3\n";
    cout<<"Los productos que usted puede elegir son los siguientes: \n";

    //Se le da informacion al usuario acerca de los farmaco
    //Numero de Producto
    //Precio
    //Descripcion
    //Las Existencias

    //Productos a elegir
    int num=1;
    int iii=0;
    for (int b=0;b<10;b++)
    {
        cout<<"Presione ("<<num++<<") para elegir "<<nombrefarmacos[b]<<"\n"
            <<"Precio: Q"<<preciofarmacos[b]<<"\n"
            <<"Descripcion: "<<descripcionfarmacos[b]<<" "<<"("<<cantidadfarmacos[b]<<")"<<"\n"
            <<"Las existencias de este producto son: "<<existenciasfarmacos [b]<<"\n\n";

    }

    ii=0;
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
                if (existenciasfarmacos[0]!=0)
                {
                    suma=suma+preciofarmacos[0];
                    sumacl=sumacl+preciofarmacos[0];
                    existenciasfarmacos [0]--;
                    ii++;
                    iii++;
                }
                else
                {
                    cout<<"No hay existencias\n";
                }
                break;
            }
            case 2:
            {
                if (existenciasfarmacos[1]!=0)
                {
                    suma=suma+preciofarmacos[1];
                    sumacl=sumacl+preciofarmacos[1];
                    existenciasfarmacos [1]--;
                    ii++;
                    iii++;
                }
                else
                {
                    cout<<"No hay existencias\n";
                }
                break;
            }
            case 3:
            {
                if (existenciasfarmacos[2]!=0)
                {
                    suma=suma+preciofarmacos[2];
                    sumacl=sumacl+preciofarmacos[2];
                    existenciasfarmacos [2]--;
                    ii++;
                    iii++;
                }
                else
                {
                    cout<<"No hay existencias\n";
                }
                break;
            }
            case 4:
            {
                if (existenciasfarmacos[3]!=0)
                {
                    suma=suma+preciofarmacos[3];
                    sumacl=sumacl+preciofarmacos[3];
                    existenciasfarmacos [3]--;
                    ii++;
                    iii++;
                }
                else
                {
                    cout<<"No hay existencias\n";
                }
                break;
            }
            case 5:
            {
                if (existenciasfarmacos[4]!=0)
                {
                    suma=suma+preciofarmacos[4];
                    sumacl=sumacl+preciofarmacos[4];
                    existenciasfarmacos [4]--;
                    ii++;
                    iii++;
                }
                else
                {
                    cout<<"No hay existencias\n";
                }
                break;
            }
            case 6:
            {
                if (existenciasfarmacos[5]!=0)
                {
                    suma=suma+preciofarmacos[5];
                    sumacl=sumacl+preciofarmacos[5];
                    existenciasfarmacos [5]--;
                    ii++;
                    iii++;
                }
                else
                {
                    cout<<"No hay existencias\n";
                }
                break;
            }
            case 7:
            {
                if (existenciasfarmacos[6]!=0)
                {
                    suma=suma+preciofarmacos[6];
                    sumacl=sumacl+preciofarmacos[6];
                    existenciasfarmacos [6]--;
                    ii++;
                    iii++;
                }
                else
                {
                    cout<<"No hay existencias\n";
                }
                break;
            }
            case 8:
            {
                if (existenciasfarmacos[7]!=0)
                {
                    suma=suma+preciofarmacos[7];
                    sumacl=sumacl+preciofarmacos[7];
                    existenciasfarmacos [7]--;
                    ii++;
                    iii++;
                }
                else
                {
                    cout<<"No hay existencias\n";
                }
                break;
            }
            case 9:
            {
                if (existenciasfarmacos[8]!=0)
                {
                    suma=suma+preciofarmacos[8];
                    sumacl=sumacl+preciofarmacos[8];
                    existenciasfarmacos [8]--;
                    ii++;
                    iii++;
                }
                else
                {
                    cout<<"No hay existencias\n";
                }
                break;
            }
            case 10:
            {
                if (existenciasfarmacos[9]!=0)
                {
                    suma=suma+preciofarmacos[9];
                    sumacl=sumacl+preciofarmacos[9];
                    existenciasfarmacos [9]--;
                    ii++;
                    iii++;
                }
                else
                {
                    cout<<"No hay existencias\n";
                }
                break;
            }
            default:{
                mensajeError();
                break;
            }
        }
    }
    while(modulo1!=0&&iii<3);
    cout<<"\n";
    cout<<"El total a pagar es de "<<"Q"<<sumacl<<"\n"
        <<"El total de productos que usted comprara es de "<<ii<<"\n\n";

    if(ii!=0) {
        cout<<"¿Usted cuenta con seguro?\n"
            <<"Presione 1 para si y cualquier otro numero para no\n";
        cin>>descuentoseguro;


        if (descuentoseguro==1)
        {
            int dess;
            double descuentoaplicado=0;
            cout<<"Ingrese el seguro con el que usted cuenta\n";
            cout<<"1=Seguros GyT\n"
                <<"2=Seguro Agromercantil\n"
                <<"3=Aseguradora General, S.A.\n"
                <<"4=Seguros el Roble\n"
                <<"5=Mapfre\n";

            cin>>dess;
            switch (dess)
            {
                // Añadí esto para que en mi modulo se vea cuales son los seguros que se usan
                case 1:
                {
                    descuentoaplicado=sumacl*0.75;
                    gyt++;
                    break;
                }
                case 2:
                {
                    descuentoaplicado=sumacl*0.40;
                    agro++;
                    break;
                }
                case 3:
                {
                    descuentoaplicado=sumacl*0.60;
                    gene++;
                    break;
                }
                case 4:
                {
                    descuentoaplicado=sumacl*0.5;
                    robl++;
                    break;
                }
                case 5:
                {
                    descuentoaplicado=sumacl*0.25;
                    mapf++;
                    break;
                }
                default:{
                    mensajeError();
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
            <<"Ingrese la fecha de vencimiento de la tarjeta, ejemplo:4/23\n";
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
}

void modulo2(){

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
    if (seguro<=4){
        cout << aseguradora[seguro] << endl;
        cout << "Su copago es: \n"
             << (tazaDescuento[seguro]) * 100 << "%" << endl;
    }
    //Aqui se Muestra la informacion de la aseguradora seleccionada
    else {
        mensajeError();
    }

}

void modulo3(){
    // Puse esta variable local "info" para que el admin decida que tipo de informacion desplegar
    int info;

    cout << "Ingrese el tipo de información que desea ver" << "\n";
    do
    {
        cout << "Ingrese 1 para desplegar la informacion de la famacia \n";
        cout << "Ingrese 2 para desplegar la información de las aseguradoras \n";
        cout << "Si desea salir de este modulo presione 0\n";
        cin >> info;
        switch (info)
        {
            case 1:{
                cout<<"Resumen del día \n";
                cout << "Inventario de medicamentos:  \n";
                for (int i = 0; i < 10; i++) {
                    cout << nombrefarmacos[i] << "\n"
                         << existenciasfarmacos[i] << "\n";
                }
                cout << "El total de productos que llevaron el día de hoy son: "<<ii<<"\n";
                cout << "EL Total de ventas en quetzales es de: " << suma<<"\n";
                cout << "Los clientes que compraron el día de hoy: \n";
                cout << lola << "\n";
                cout <<"El nombre de los clientes que compraron son:\n";
                for (int i = 0; i < lola ; ++i) {
                    cout<<nombre[i]<<endl;
                }
                cout << "\n";
                break;
            }
            case 2:{

                if (descuentoseguro==1){
                    cout << titulartarjeta ;
                    cout << "Informacion de las aseguradoras\n";
                    cout <<  "Seguros Gyt " <<"cuenta con "<<gyt <<" clientes"<<"\n";
                    cout << "Seguro Agromercantil " <<"cuenta con "<< agro <<" clientes" "\n";
                    cout << "Seguro General " <<"cuenta con "<<gene <<" clientes" "\n";
                    cout <<  "Seguros el Roble " <<"cuenta con "<<robl <<" clientes" "\n";
                    cout << "Seguros Mapfre " <<"cuenta con "<<mapf <<" clientes" "\n";
                    cout<<"\n";
                    // cout << "El seguro mas utilizado es: " << juancho << "\n";
                    map<string, int>map1;
                    map1["Seguros GyT"] = gyt;
                    map1["Seguro Agromercantil"] = agro;
                    map1["Seguro General"] = gene;
                    map1["Seguros el Roble"] = robl;
                    map1["Seguros Mapfre"] = mapf;

                    map<string, int>::iterator it;
                    int min = INT_MAX, max = INT_MIN;
                    string nombre = "";
                    for (it = map1.begin(); it != map1.end(); it++)
                    {
                        if (it->second > max) {
                            max = it->second;
                            nombre = it->first;
                        }
                    }
                    std::cout<< "El seguro mas usado es: " << nombre
                              << ": "
                              << max
                              << std::endl;
                    cout<<"\n";

                }
                else {
                    cout<<"No hay cliente con seguro"<<endl;
                    cout<<"\n";
                }
                break;
            }
            default:{
                mensajeError();
                break;
            }
        }

    }
    while (info!=0);

}

void modulo4(){
    int accion;
    do {
        //Seleccion de accion del Administrador
        cout <<"¿Que desea hacer?\n"
             <<"1=Crear Usuarios\n"
             <<"2=Modificacion de Existencias\n"
             <<"3=Bloquear o Desbloquear Usuarios\n"
             <<"4=Cambiar Contraseñas\n"
             <<"5=Ver las ventas totales\n"
             <<"0=Cerrar modulo\n"
             <<endl;
        cin>>accion;

        //Creacion de usuarios
        switch (accion) {
            case 0:{
                cout<<"Módulo cerrado correctamente"<<endl;
                break;
            }
            case 1:{
                cout<<"Ingrese la información del usuario que desea crear\n";
                //Usuario
                cout<<"Ingrese el usuario"<<endl;
                cin>>usuario[contador];
                //Nombre
                cout<<"Ingrese el nombre de la persona"<<endl;
                cin>>name[contador];
                //Apellido
                cout<<"Ingrese el apellido de la persona"<<endl;
                cin>>lastName[contador];
                //Rol
                cout<<"Ingrese el rol de la persona 0=cliente 1=Dependiente"<<endl;
                cin>>rol[contador];
                //Contraseña
                cout<<"Ingrese la contraseña del usuario"<<endl;
                cin>>password[contador];
                //Estado (Bloquedo o no Bloqueado)
                cout<<"¿Está bloqueado el usuario 1=si, 0=no?"<<endl;
                cin>>bloqueado[contador];
                contador++;
                break;
            }
            case 2:{
                int switchcase;
                do {
                    int numero = 1;
                    for (auto & nombrefarmaco : nombrefarmacos) {
                        cout << "Presione (" << numero++ << ") para elegir " << nombrefarmaco << "\n";
                    }
                    cout << "Ingrese el articulo al cual le quiere modificar las existencias o cero para finalizar el proceso\n";
                    cin >> switchcase;
                    switch (switchcase) {
                        case 0:
                        {
                            cout<<"Cambios realizados\n";
                            break;
                        }
                        case 1: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[0]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[0];
                            break;
                        }
                        case 2: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[1]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[1];
                            break;
                        }
                        case 3: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[2]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[2];
                            break;
                        }
                        case 4: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[3]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[3];
                            break;
                        }
                        case 5: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[4]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[4];
                            break;
                        }
                        case 6: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[5]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[5];
                            break;
                        }
                        case 7: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[6]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[6];
                            break;
                        }
                        case 8: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[7]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[7];
                            break;
                        }
                        case 9: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[8]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[8];
                            break;
                        }
                        case 10: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[9]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[9];
                            break;
                        }
                        default:{
                            mensajeError();
                            break;
                        }
                    }

                }
                while (switchcase != 0);
                break;
            }
            case 3:{
                int verificar1=0,e=0;
                string estadoUsuario;
                cout<<"Los usuarios bloquedos son: "<<endl;
                for(int a=0;a<200;a++){
                    if (bloqueado[a]==1){
                        cout<<usuario[a]<<endl;
                    }
                }
                cout<<"Ingrese el usuario al que le quiera cambiar el estado (bloqueado o desbloqueado)"<<endl;
                cin>>estadoUsuario;
                for(int b=0;b<200;b++){
                    if (estadoUsuario==usuario[b]){
                        b=e;
                        verificar1=1;
                    }
                }
                if (verificar1==1){
                    cout<<"El usuario seleccionado fue: "<<usuario[e]<<endl;
                    cout<<"Presione 0=para desbloquear y 1=para bloquear"<<endl;
                    cin>>bloqueado[e];
                }
                else{
                    cout<<"Error el usuario seleccionado no está en la lista"<<endl;
                }
                break;
            }
            case 4:{
                int verificar2=0, posicion=0;
                string usuarioSeleccionado;
                cout<<"Ingrese el usuario al que le quiere cambiar la contraseña"<<endl;
                cin>>usuarioSeleccionado;
                for(int c=0;c<200;c++){
                    if (usuarioSeleccionado==usuario[c]){
                        c=posicion;
                        verificar2=1;
                    }
                }
                if (verificar2==1){
                    cout<<"El usuario seleccionado fue: "<<usuario[posicion]<<endl;
                    cout<<"Coloque la nueva contraseña"<<endl;
                    cin>>password[posicion];
                }
                else{
                    cout<<"Error el usuario seleccionado no está en la lista"<<endl;
                }
                break;
            }
            case 5:{
                cout << "El total de ventas es: \n";
                cout << suma << "\n";
                break;
            }
            default:{
                cout<<"Error entrada no válida"<<endl;
                break;
            }
        }
    }
    while (accion!=0);
}
void mensajeError(){
    cout<<"Error valor ingresado no válido"<<endl;
}
//esto essss randy piña