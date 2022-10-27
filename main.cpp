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
//Tamaño del farmaco
string cantidadfarmacos[10]{"100 tabletas","2 ampollas","ml ","ml","12 tabletas","20 tabletas","12 tabletas","100 tabletas","100 comprimidos","2 ampollas",};

//Modulo 1
//Precio de los farmacos
float preciofarmacos[10]{186.95,26.00,64.99,33.02,26.95,28.20,559.98,96.76,104.75,50.38};

//Modulo 1
//Existencias de los farmacos
double existenciasfarmacos[10]{20,20,20,20,20,20,20,20,20,20};

//Modulo 2
//Aseguradoras Usadas
string aseguradora[5]{"Seguros GyT","Seguro Agromercantil","Aseguradora General, S.A.","Seguros El Roble","Mapfre"};
// Contadores para las aseguradoras
int gyt=0;
int agro=0, gene=0, robl=0, mapf=0;

//Modulo 2
//Taza de descuento fija
float tazaDescuento[5]{0.25,0.60,0.40,0.5,0.75,};
//Información del comprador
string titulartarjeta,fechavencimiento,codigotarjeta,numerotarjeta;
//suma total de todos los articulos comprados en el día
float suma=0.0;
//Variable que guarda el numero asignado a la aseguradora
int seguro=0;
//Variable que guarda el descuento asignado de cada aseguradora
int descuentoseguro;
//Contador para el arreglo de los nombres
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
        //Se compreuba que el usuario y la contraseña sean los correctos
        if (nombreADMIN=="ADMIN"&&contraADMIN=="admin"){
            //Se ejecuta el modulo 4
            modulo4();
        }
        //En caso de no ser la misma se da un mensaje de error
        else {
            cout<<"ERROR: Usuario o Contraseña de administrador incorrectos"<<endl;
        }
    }

   //Esto es para que se ejecute hasta que el usuario y la contraseña sean los correctos
    while (nombreADMIN!="ADMIN"||contraADMIN!="admin");
    //Se ejecutan la seleccion de usuarios
    do{
        //Se le pide que seleccione su rol
        cout<<"Bienvenido a Farmacias Batres"<<endl;
        cout<<"¿Quien es usted?\n"
            <<"1=Cliente\n"
            <<"2=Empleado\n"
            <<"3=Otro\n"
            <<"0=Finalizar Ejecución\n";
        //Se ingresa el rol deseado
        cin>>rolIngresado;
        //Caso en el que el rol ingresado sea cliente
        if (rolIngresado==1){
            //No. de Intentos restantes
            int intentos=0;
            //Se le pide que ingrese el usuario
            cout<<"Usuario"<<endl;
            cin>>nombreCliente;
            int usuarioCorrecto=0;
            //Verificar que la contraseña sea correcta
            int contraCorrecta=0;

            for (int contadorG=0;contadorG<200;contadorG++){
                while(nombreCliente==usuario[contadorG]&&rol[contadorG]==0&&bloqueado[contadorG]!=1&&contraCorrecta!=1){
                    usuarioCorrecto=1;
                    cout << "Contraseña" << endl;
                    cin >> contraCliente;
                    if (contraCliente == password[contadorG]) {
                        contraCorrecta=1;
                    }
                    else {
                        cout<<"Contraseña incorrecta, por favor vuelva a intentarlo."<<endl;
                        intentos++;
                        cout<<"Intentos restantes: "<<3-intentos<<endl;
                    }
                    if(intentos>=3){
                        bloqueado[contadorG]=1;
                        cout<<"Error el usuario se bloqueo por el uso de demasiados intentos"<<endl;
                    }
                }
            }
            if (usuarioCorrecto==0) {
                cout<<"Error, Usuario no encotrado o bloqueado, por ingrese de nuevo el usuario o contactese con el administrador"<<endl;
            }
            //Verifica que la contraseña ingresada sea la correcta
            if (contraCorrecta==1) {
                //Se ejetuan los modulos hasta que no se cumpla la condicion
                do {
                    //Se le pregunta a que modulo quieren ingresar
                    cout << "¿A que modulo quieres ingresar?\n"
                         << "1=Farmacias\n"
                         << "2=Seguros\n"
                         << "0=Cerrar Sesión\n"
                         << endl;
                    //ingresan el modulo al que quieren acceder
                    cin >> modulo;
                    //Se seleccionan los casos del módulo
                    switch (modulo) {
                        //Caso 0 se cierra la sesión
                        case 0:{
                            cout<<"Sesion cerrada con éxito"<<endl;
                            break;
                        }
                            //Caso 1 se ejercuta el módulo 1
                        case 1: {
                            modulo1();
                            break;
                        }
                            //caso 2 se ejecuta el modulo 2
                        case 2: {
                            modulo2();
                            break;
                        }
                            //Mensaje de error
                        default: {
                            cout << "Error valor no valido" << endl;
                            break;
                        }
                    }
                }
                    //Condicion que se tiene que cumplir para salir del ciclo
                while (modulo!=0);

            }

        }
        else if (rolIngresado==2){
            //Ingresan el usuario
            cout<<"Usuario"<<endl;
            cin>>nombreDep;

            //Ingresan la contraseña
            cout<<"Contraseña"<<endl;
            cin>>contraDep;

            //Se crea el contador
            contadorGeneral=0;
            //Se verifica que en toda la base de datos
            while (contadorGeneral<200){
                //Se verifica que el usuario este en la base de datos
                if (nombreDep==usuario[contadorGeneral]&&contraDep==password[contadorGeneral]&&rol[contadorGeneral]==1){
                    //Variable que verifica que si es dependiente
                    dependiente=1;
                }
                //Suma al contador
                contadorGeneral++;
            }
            //Si dependiente se verifico en el la base de datos y existe entonces
            if (dependiente==1){
                //Se ejecutan los modulos en bucle hasta que se cierre sesion
                do{
                    //Se le pide que ingresen al módulo deseado
                    cout<<"¿A que modulo quieres ingresar?\n"
                        <<"1=Farmacias\n"
                        <<"2=Seguros\n"
                        <<"3=Reportes\n"
                        <<"0=Cerrar Sesión\n"
                        <<endl;
                    cin>>modulo;
                    //Se evalua modulo
                    switch (modulo) {
                        //Caso 0: Se ejecuta cierre de sesion
                        case 0:{
                            cout<<"Sesión cerrada con éxito"<<endl;
                            break;
                        }
                        //Caso 1: Se ejercuta el modulo 1
                        case 1:{
                            modulo1();
                            break;
                        }
                        //Caso 2: Se ejecuta el modulo 2
                        case 2:{
                            modulo2();
                            break;
                        }
                        //Caso 3: Se ejecuta el modulo 3
                        case 3:{
                            modulo3();
                            break;
                        }
                        //Se da un mensaje de error si no se cumplen con los parametros desados.
                        default:{
                            cout<<"Error valor no valido"<<endl;
                            break;
                        }
                    }
                }
                //Condicion para salir de los modulos
                while (modulo!=0);
            }
            //Mensaje de error si el usuario o cantraseña son incorrectos
            else {
               cout<<"Empleado no econtrado, por favor pruebe de nuevo"<<endl;
            }
        }
        //En caso de que ingresen a Otro caso se verifica si el usuario es el administrador
        else if (rolIngresado==3){
            //Ingresan el usuario
            cout<<"Usuario"<<endl;
            cin>>nombreADMIN;
            //Ingresan la contraseña
            cout<<"Contraseña"<<endl;
            cin>>contraADMIN;
            //Se usa el mismo contador general
            contadorGeneral=0;
            //Se verifica en la base de que el usuario y la contraseña sea la de administrador
            while (contadorGeneral<200){
                if (nombreADMIN=="ADMIN"&&contraADMIN=="admin"){
                    //Se verifica que el administrador sea correcto
                    administrador=1;
                }
                contadorGeneral++;
            }
            //Si administrador se verifica como correcto
            if (administrador==1){
                //Se ejecuta el ciclo de seleccion de modulos hasta que se cierre sesion
                do {
                    //Se le pide al usuario que ingrese al modulo que quiera ingresar
                    cout<<"¿A que modulo quieres ingresar?\n"
                        <<"1=Farmacias\n"
                        <<"2=Seguros\n"
                        <<"3=Reportes\n"
                        <<"4=Administrar\n"
                        <<"0=Cerrar Sesión\n"
                        <<endl;
                    cin>>modulo;
                    //Se evalua la variable modulo
                    switch (modulo) {
                        //Caso 0: Se cierra sesion
                        case 0:{
                            cout<<"Sesión cerrada con éxito"<<endl;
                            break;
                        }
                        //Caso 1: Se ejecuta el modulo 1
                        case 1:{
                            modulo1();
                            break;
                        }
                        //Caso 2: Se ejecutal el modulo 2
                        case 2:{
                            modulo2();
                            break;
                        }
                        //Caso 3: Se ejecuta el modulo 3
                        case 3:{
                            modulo3();
                        }
                        //Caso 4: Se ejecuta el modulo 4
                        case 4:{
                            modulo4();
                            break;
                        }
                        //Mesaje de error
                        default:{
                            cout<<"Error valor no valido"<<endl;
                            break;
                        }
                    }
                }
                //Condicion para terminar la seleccion de modulo
                while (modulo!=0);
            }
            //Se le muestra mensaje de error si el usuario y contraseña administrador son incorrectos
            else {
                cout<<"Usuario administrador incorrecto,por favor pruebe de nuevo"<<endl;
            }
        }
    }
    //Se ejecuta el condigo mientras el rol no sea 0
    while(rolIngresado!=0);
    //Termina ejecucion
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
    //Visualiza la información de los productos disponibles
    for (int b=0;b<10;b++)
    {
        cout<<"Presione ("<<num++<<") para elegir "<<nombrefarmacos[b]<<"\n"
            <<"Precio: Q"<<preciofarmacos[b]<<"\n"
            <<"Descripcion: "<<descripcionfarmacos[b]<<" "<<"("<<cantidadfarmacos[b]<<")"<<"\n"
            <<"Las existencias de este producto son: "<<existenciasfarmacos [b]<<"\n\n";

    }

    ii=0;
    //Compra de medicamentos
    //Los "if" muestran cuando si hay exitencias
    //Los "else" muestran cuando no hay existencias
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
        //Contador que permite que funcione el if
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
    //Subtotal a pagar
    cout<<"El total a pagar es de "<<"Q"<<sumacl<<"\n"
        <<"El total de productos que usted comprara es de "<<ii<<"\n\n";
    //Pregunta para ver si el usuario cuenta con seguro
    if(ii!=0) {
        cout<<"¿Usted cuenta con seguro?\n"
            <<"Presione 1 para si y cualquier otro numero para no\n";
        cin>>descuentoseguro;
    //Pregunta al usuario para ver con que seguros cuenta
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
                //aplicacion del descuento de cada seguro
                case 1:
                {
                    //Proceso que aplica el descuento de la aseguradora
                    descuentoaplicado=sumacl*(1-tazaDescuento[0]);
                    //contador de clientes de seguro gyt
                    gyt++;
                    break;
                }
                case 2:
                {
                    //Proceso que aplica el descuento de la aseguradora
                    descuentoaplicado=sumacl*(1-tazaDescuento[1]);
                    //contador de clientes de seguro agromercantil
                    agro++;
                    break;
                }
                case 3:
                {
                    //Proceso que aplica el descuento de la aseguradora
                    descuentoaplicado=sumacl*(1-tazaDescuento[2]);
                    //contador de clientes de Aseguradora general
                    gene++;
                    break;
                }
                case 4:
                {
                    //Proceso que aplica el descuento de la aseguradora
                    descuentoaplicado=sumacl*(1-tazaDescuento[3]);
                    //contador de cliente sde seguros el Roble
                    robl++;
                    break;
                }
                case 5:
                {
                    //Proceso que aplica el descuento de la aseguradora
                    descuentoaplicado=sumacl*(1-tazaDescuento[4]);
                    //contador de clientes de seguro Mapfre
                    mapf++;
                    break;
                }
                default:{
                    //Mensaje de error por datos mal ingresados
                    mensajeError();
                    break;
                }
            }
            //Mensaje del nuevo subtototal con el nuevo seguro aplicado
            cout<<"El nuevo total a pagar con el descuento aplicado es de "<<descuentoaplicado<<"\n";
        }
        else {
            //Mensaje a clientes que no cuenten con seguro
            cout<<"usted no cuenta con un seguro\n";
        }
        //Información de pago para el cliente
        cout<<"Ingrese la información de la tarjeta para pagar:\n\n"
            <<"Ingrese el nombre del titular de la tarjeta:\n";
        cin>>nombre[lola];
        //contador que recorre el arreglo de los nombres
        lola++;
        //Datos de la tarjeta de credito para que ingrese el usuario
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
            <<" PAGO EXITOSO\n\n";
    }
}

void modulo2(){

    //Inicia el Modulo 2
    //Variable que selecciona el seguro

    //Pido al usuario que ingrese el seguro
    cout<<"Módulo de Seguros"<<endl;
    //Mensaje de que el numero asignado con el seguro
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
                // si la variable descuentoseguro toma el valor de 1 significa que el usuario si cuenta con aseguradora
                if (descuentoseguro==1){
                    //informacion de las aseguradoras
                    cout << titulartarjeta ;
                    cout << "Informacion de las aseguradoras\n";
                    cout <<  "Seguros Gyt " <<"cuenta con "<<gyt <<" clientes"<<"\n";
                    cout << "Seguro Agromercantil " <<"cuenta con "<< agro <<" clientes" "\n";
                    cout << "Seguro General " <<"cuenta con "<<gene <<" clientes" "\n";
                    cout <<  "Seguros el Roble " <<"cuenta con "<<robl <<" clientes" "\n";
                    cout << "Seguros Mapfre " <<"cuenta con "<<mapf <<" clientes" "\n";
                    cout<<"\n";
                    //Variable que almacena a la aseguradora con mas clientes
                    int mayor;
                    //Variable que toma el valor del numero asignado de la aseguradora con mas clientes
                    int band=1;
                    for (int i=0;i<5;i++)
                    {
                        if (i==0)
                        {
                            //mayor toma el valor de GyT
                            mayor=gyt;
                        }
                        else
                        {
                            if (agro>mayor)
                            {
                                //mayor toma el valor de agro
                                mayor=agro;
                                //band toma el valor de 2
                                band=2;
                            }
                            else if (gene>mayor)
                            {
                                //mayor toma el valor de gene
                                mayor=gene;
                                //band toma el valor de 3
                                band=3;
                            }
                            else if (robl>mayor)
                            {
                                //mayor toma el valor de robl
                                mayor=robl;
                                //band toma el valor de 4
                                band=4;
                            }
                            else if (mapf>mayor)
                            {
                                //mayor toma el valor de mapf
                                mayor=mapf;
                                //band toma el valor de 5
                                band=5;
                            }
                        }
                    }
                    //Dependiendo del valor que tome band se seleccionará el caso de switchcase
                    //band toma el valor de la aseguradora con más clientes
                    switch (band)
                    {
                        case 1:
                        {
                            //Mensaje de la aseguradora con más clientes
                            cout<<"El seguro con más clientes es Seguro GyT\n";
                            break;
                        }
                        case 2:
                        {
                            //Mensaje de la aseguradora con más clientes
                            cout<<"El seguro con más clientes es Seguro Agromercantil\n";
                            break;
                        }
                        case 3:
                        {
                            //Mensaje de la aseguradora con más clientes
                            cout<<"El seguro con más clientes es Seguro General\n";
                            break;
                        }
                        case 4:
                        {
                            //Mensaje de la aseguradora con más clientes
                            cout<<"El seguro con más clientes es Seguros El Roble\n";
                            break;
                        }
                        case 5:
                        {
                            //Mensaje de la aseguradora con más clientes
                            cout<<"El seguro con más clientes es Seguros Mapfre\n";
                            break;
                        }
                    }
                    }
                else {
                    //mensaje de que no se utilizo ninguna aseguradora
                    cout<<"No se uso ninguna seguradora\n";
                }
                break;
            }
            default:{
                //Se llama a la función mensajeError() para que muestre un mensaje de error
                mensajeError();
                break;
            }
        }

    }
    //funciona hasta que el usuario presione el 0
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
             <<"6=Modificar la cuota de descuento de los seguros\n"
             <<"0=Cerrar modulo\n"
             <<endl;
        cin>>accion;

        //Creacion de usuarios
        switch (accion) {
            //Caso 0 Cierra el modulo
            case 0:{
                cout<<"Módulo cerrado correctamente"<<endl;
                break;
            }
            //Caso 1: Creacion de usuarios
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
            //Caso 2 Modificar la exitencia de los farmacos
            case 2:{
                //Varaible que selecciona el numero de medicamento
                int switchcase;
                //Se le pide al usuario que seleccionen los medicamentos hasta que se cumpla con una condicion
                do {
                    //Se le muestran los famarmacos
                    int numero = 1;
                    for (auto & nombrefarmaco : nombrefarmacos) {
                        cout << "Presione (" << numero++ << ") para elegir " << nombrefarmaco << "\n";
                    }
                    //Se le pide que ingrese las medicina al que se quiere modificar las existencias
                    cout << "Ingrese el articulo al cual le quiere modificar las existencias o cero para finalizar el proceso\n";
                    cin >> switchcase;
                    //Se evalua switchcase
                    switch (switchcase) {
                        //Se muestra que se modificaron las existencias correctamente
                        case 0:
                        {
                            cout<<"Cambios realizados\n";
                            break;
                        }
                        //Medicina 1
                        case 1: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[0]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[0];
                            break;
                        }
                        //Medicina 2
                        case 2: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[1]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[1];
                            break;
                        }
                        //Medicina 3
                        case 3: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[2]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[2];
                            break;
                        }
                        //Medicina 4
                        case 4: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[3]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[3];
                            break;
                        }
                        //Medicina 5
                        case 5: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[4]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[4];
                            break;
                        }
                        //Medicina 6
                        case 6: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[5]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[5];
                            break;
                        }
                        //Medicina 7
                        case 7: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[6]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[6];
                            break;
                        }
                        //Medicina 8
                        case 8: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[7]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[7];
                            break;
                        }
                        //Meidcina 9
                        case 9: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[8]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[8];
                            break;
                        }
                        //Medicina 10
                        case 10: {
                            cout << "La existencia del farmaco es de " << existenciasfarmacos[9]<<"\n";
                            cout << "Ingrese el nuevo valor de la existencia\n";
                            cin >> existenciasfarmacos[9];
                            break;
                        }
                        //Mesaje de error
                        default:{
                            mensajeError();
                            break;
                        }
                    }

                }
                //Condicion para salir de la modificacion de medicinas
                while (switchcase != 0);
                break;
            }
            //Caso 3: Bloquear o desbloquear
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
            //Caso 4: Cambiar contraseñas al usuario
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
            //Caso 5: Muestra la suma total de las ventas
            case 5:{
                cout << "El total de ventas es: \n";
                cout << suma << "\n";
                break;
            }
            case 6:{
                int seguroModificado=0;
                string nuevaTaza;
                cout<<"La taza de actual descuento de los seguros es: "<<endl;
                for(int d=0;d<5;d++){
                    cout<<aseguradora[d]<<": "<<tazaDescuento[d]*100<<"%\n";
                }
                cout<<"Ingrese el seguro al que quiere modificarle la taza: "<<endl;
                cin.ignore();
                getline(cin,nuevaTaza);
                for (int nT=0;nT<5;nT++){
                    if (nuevaTaza==aseguradora[nT]){
                        cout<<"Ingrese la nueva taza de descuento para el seguro (Numeros Enteros)"<<endl;
                        cin>>tazaDescuento[nT];
                        tazaDescuento[nT]=tazaDescuento[nT]/100;
                        seguroModificado=1;
                    }
                }
                if (seguroModificado==0){
                    mensajeError();
                }
                break;
            }
            //Mesaje de error
            default:{
                cout<<"Error entrada no válida"<<endl;
                break;
            }
        }
    }
    //Condicion que cierra el modulo
    while (accion!=0);
}
//Funcion de mensaje de error, solo para ahorrar codigo
void mensajeError(){
    cout<<"Error valor ingresado no válido"<<endl;
}