#include <iostream>
#include <string>

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
    //Numero de intentos fallidos
    int numeroFallas=0;
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

    cout<<"Hola administrador!!! Por favor realiza la configuración inicial de los usuarios."<<endl;

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
    while (nombreADMIN!="ADMIN"&&contraADMIN!="admin");

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
                    cout << "¿A que modulo quieres ingresar?\n"
                         << "1=Farmacias\n"
                         << "2=Seguros\n"
                         << "Finalizar Ejecicion\n"
                         << endl;
                    cin >> modulo;
                    switch (modulo) {
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
                        }
                    }
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
                cout<<"¿A que modulo quieres ingresar?\n"
                    <<"1=Farmacias\n"
                    <<"2=Seguros\n"
                    <<"3=Reportes\n"
                    <<"Finalizar Ejecicion\n"
                    <<endl;
                cin>>modulo;
                switch (modulo) {
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
            else {
                numeroFallas++;
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
                cout<<"¿A que modulo quieres ingresar?\n"
                    <<"1=Farmacias\n"
                    <<"2=Seguros\n"
                    <<"3=Reportes\n"
                    <<"4=Administrar\n"
                    <<"Finalizar Ejecicion\n"
                    <<endl;
                cin>>modulo;
                switch (modulo) {
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
            else {
                numeroFallas++;
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

    cout<<"Los productos que usted puede elegir son los siguientes: \n";

    //Se le da informacion al usuario acerca de los farmaco
    //Numero de Producto
    //Precio
    //Descripcion
    //Las Existencias

    //Productos a elegir
    int num=1;
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
                suma=suma+preciofarmacos[0];
                sumacl=sumacl+preciofarmacos[0];
                existenciasfarmacos [0]--;
                ii++;
                break;

            }
            case 2:
            {
                suma=suma+preciofarmacos[1];
                sumacl=sumacl+preciofarmacos[1];
                existenciasfarmacos [1]--;
                ii++;
                break;
            }
            case 3:
            {
                suma=suma+preciofarmacos[2];
                sumacl=sumacl+preciofarmacos[2];
                existenciasfarmacos [2]--;
                ii++;
                break;
            }
            case 4:
            {
                suma=suma+preciofarmacos[3];
                sumacl=sumacl+preciofarmacos[3];
                existenciasfarmacos [3]--;
                ii++;
                break;
            }
            case 5:
            {
                suma=suma+preciofarmacos[4];
                sumacl=sumacl+preciofarmacos[4];
                existenciasfarmacos [4]--;
                ii++;
                break;
            }
            case 6:
            {
                suma=suma+preciofarmacos[5];
                sumacl=sumacl+preciofarmacos[5];
                existenciasfarmacos [5]--;
                ii++;
                break;
            }
            case 7:
            {
                suma=suma+preciofarmacos[6];
                sumacl=sumacl+preciofarmacos[6];
                existenciasfarmacos [6]--;
                ii++;
                break;
            }
            case 8:
            {
                suma=suma+preciofarmacos[7];
                sumacl=sumacl+preciofarmacos[7];
                existenciasfarmacos [7]--;
                ii++;
                break;
            }
            case 9:
            {
                suma=suma+preciofarmacos[8];
                sumacl=sumacl+preciofarmacos[8];
                existenciasfarmacos [8]--;
                ii++;
                break;
            }
            case 10:
            {
                suma=suma+preciofarmacos[9];
                sumacl=sumacl+preciofarmacos[9];
                existenciasfarmacos [9]--;
                ii++;
                break;
            }
            default:{
                mensajeError();
                break;
            }
        }
    }
    while(modulo1!=0);
    cout<<"\n";
    cout<<"El total a pagar es de "<<"Q"<<sumacl<<"\n"
        <<"El total de productos que usted comprara es de "<<ii<<"\n\n";

    if(ii!=0) {
        cout<<"¿Usted cuenta con alguno de los siguientes seguro?\n"
            <<"Presione 1 para si y 0 para no\n";
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
                case 1:
                {
                    descuentoaplicado=sumacl*0.75;
                    break;
                }
                case 2:
                {
                    descuentoaplicado=sumacl*0.40;
                    break;
                }
                case 3:
                {
                    descuentoaplicado=sumacl*0.60;
                    break;
                }
                case 4:
                {
                    descuentoaplicado=sumacl*0.5;
                    break;
                }
                case 5:
                {
                    descuentoaplicado=sumacl*0.25;
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
    cout << "Ingrese 1 para desplegar la informacion de la famacia \n";
    cout << "Ingrese 2 para desplegar la información de las aseguradoras \n";
    cin >> info;
    switch (info)
    {
        case 1:{
            cout<<"Resumen del día \n";
            cout << "Inventario de medicamentos:  \n";
            for (int i = 0; i < 10; ++i) {
                cout << nombrefarmacos[i] << "\n"
                     << existenciasfarmacos[i] << "\n";

            }

            cout << "Total de ventas : \n" << endl ;
            cout << ii << "y el totales de:" << sumacl;
            cout << "Total de clientes que compraron el día de hoy: \n";
            for (int i = 0; i < lola ; ++i) {
                cout<<nombre[i]<<endl;
            }
            break;
        }

        case 2:{
            cout << "Informacion de las aseguradoras \n ";
            cout << "Los clientes que han utilizado su seguro en esta farmacia son: \n";
            if (descuentoseguro==1){
                cout << titulartarjeta ;
                cout << "\n";
                cout << "El seguro mas usado es: \n";
            }
            else {
                cout<<"No hay cliente con seguro"<<endl;
            }
            break;
        }
        default:{
            mensajeError();
            break;
        }
    }
}

void modulo4(){

    int accion;

    do {
        //Seleccion de accion del Administrador
        cout <<"¿Que desea hacer?\n"
             <<"1=Control de Accesos\n"
             <<"2=Modificacion de la Info de farmacia\n"
             <<"3=Bloquear o desbloquear usuarios\n"
             <<"4=Ver las ventas totales\n"
             <<"0=salir del modulo\n"
             <<endl;
        cin>>accion;

        //Creacion de usuarios
        if (accion==1){
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
        }

            //Estado de Farmacos
        else if(accion==2) {
            int numero = 1;
            for (auto & nombrefarmaco : nombrefarmacos) {
                cout << "Presione (" << numero++ << ") para elegir " << nombrefarmaco << "\n";
            }
            int switchcase;
            do {

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
                        cout << "La existencia del farmaco es de " << existenciasfarmacos[0];
                        cout << "Ingrese el nuevo valor de la existencia\n";
                        cin >> existenciasfarmacos[0];
                        break;
                    }
                    case 2: {
                        cout << "La existencia del farmaco es de " << existenciasfarmacos[1];
                        cout << "Ingrese el nuevo valor de la existencia\n";
                        cin >> existenciasfarmacos[1];
                        break;

                    }
                    case 3: {
                        cout << "La existencia del farmaco es de " << existenciasfarmacos[2];
                        cout << "Ingrese el nuevo valor de la existencia\n";
                        cin >> existenciasfarmacos[2];
                        break;

                    }
                    case 4: {
                        cout << "La existencia del farmaco es de " << existenciasfarmacos[3];
                        cout << "Ingrese el nuevo valor de la existencia\n";
                        cin >> existenciasfarmacos[3];
                        break;

                    }
                    case 5: {
                        cout << "La existencia del farmaco es de " << existenciasfarmacos[4];
                        cout << "Ingrese el nuevo valor de la existencia\n";
                        cin >> existenciasfarmacos[4];
                        break;

                    }
                    case 6: {
                        cout << "La existencia del farmaco es de " << existenciasfarmacos[5];
                        cout << "Ingrese el nuevo valor de la existencia\n";
                        cin >> existenciasfarmacos[5];
                        break;

                    }
                    case 7: {
                        cout << "La existencia del farmaco es de " << existenciasfarmacos[6];
                        cout << "Ingrese el nuevo valor de la existencia\n";
                        cin >> existenciasfarmacos[6];
                        break;

                    }
                    case 8: {
                        cout << "La existencia del farmaco es de " << existenciasfarmacos[7];
                        cout << "Ingrese el nuevo valor de la existencia\n";
                        cin >> existenciasfarmacos[7];
                        break;

                    }
                    case 9: {
                        cout << "La existencia del farmaco es de " << existenciasfarmacos[8];
                        cout << "Ingrese el nuevo valor de la existencia\n";
                        cin >> existenciasfarmacos[8];
                        break;

                    }
                    case 10: {
                        cout << "La existencia del farmaco es de " << existenciasfarmacos[9];
                        cout << "Ingrese el nuevo valor de la existencia\n";
                        cin >> existenciasfarmacos[9];
                        break;

                    }
                    default:{
                        mensajeError();
                        break;
                    }
                }

            } while (switchcase != 0);
        }
        //Modulo para desbloquear usuarios
        else if(accion==3){
            int b=0;
            cout<<"Los usuarios bloquedos son: "<<endl;
            for(int a=0;a<200;a++){
                if (bloqueado[a]==1){
                    cout<<usuario[a]<<"\t Está en la posición: "<<a<<endl;
                }

            }
            cout<<"Pulse la posición en la que se quiere desbloquear"<<endl;
            cin>>b;
            cout<<"Presione 0=para desbloquear y 1=para que siga bloqueado"<<endl;
            cin>>bloqueado[b];
        }
        else if (accion==4){
            cout << "El total de ventas es: \n";
            cout << suma << "\n";
        }
            //Caso 0f
        else if(accion==0){

        }
            //Mesaje de Error
        else {
            cout<<"Error entrada no válida"<<endl;
        }
    }
    while (accion!=0);

}

void mensajeError(){
    cout<<"Error valor ingresado no válido"<<endl;
}


// Esta no es