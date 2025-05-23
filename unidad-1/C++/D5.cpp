#include<iostream>
using namespace std;

struct Usuario {
    string Nombre;
    string Contraseña;
};

struct Producto {
    int id;
    string Nombre;
    double Precio;
    int Stock;
};

void Listar(Producto productos[]){
    for(int i = 0;i<3;i++){
        cout<<productos[i].id<<endl;
        cout<<productos[i].Nombre<<endl;
        cout<<productos[i].Precio<<endl;
        cout<<productos[i].Stock<<endl;
    }
}

void MenuSistema(Usuario usuario);

bool EsMayuscula(char c) {
    return c >= 'A' && c <= 'Z';
}

bool EsSimboloEspecial(char c) {
    string simbolos = "!@#$%^&*()-_+=<>?/";
    for (int i = 0; i < simbolos.length(); i++) {
        if (c == simbolos[i]) {
            return true;
        }
    }
    return false;
}

bool ValidarContrasena(string contrasena) {
    bool tieneMayuscula = false;
    bool tieneSimbolo = false;
    bool cantidad = false;

    for (int i = 0; i < contrasena.length(); i++) {
        if (EsMayuscula(contrasena[i])) {
            tieneMayuscula = true;
        }
        if (EsSimboloEspecial(contrasena[i])) {
            tieneSimbolo = true;
        }
        if(contrasena.size()>8 && contrasena.size()<16) {
            cantidad = true;
        }
    }

    return tieneMayuscula && tieneSimbolo && cantidad;
}

Usuario CrearUsuario(){
    Usuario usuario;
    do{
    cout<<"--Ingrese Nombre de su usuario "<<endl;
    cin>>usuario.Nombre;
    cout<<"--ingrese Contrasena de su nuevo usuario: " <<endl;
    cin>>usuario.Contraseña;

    if (ValidarContrasena(usuario.Contraseña)) {
        cout << "Contrasena valida." << endl;
        return usuario;
    } else {
        cout << "La contrasena debe tener al menos 1 mayuscula y 2 simbolos especiales." << endl;
        cout<<"--intente de nuevo--"<<endl;
    }
}
while (ValidarContrasena);


    return usuario;
};

void VerificarUsuario(Usuario usuario) {

    cout<<"--Ingrese su contrasena"<<endl;
    string contraseña;
    for(int i = 0; i<3 ;i++){
    cin>>contraseña;


    if(usuario.Contraseña == contraseña){
        cout<<"Bienvenido: "<< usuario.Nombre<<endl;
        MenuSistema(usuario);
        return;
    }
    else {
        cout<<"Intente de nuevo, 'usuario'-_-"<<endl;
        }
    }
    cout<<"BLOQUEADO"<<endl;
}

void Login(Usuario usuario){
    int valor;
 
    cout<<"--Menu"<<endl;
    cout<<"1-Ingresar al sistema "<<endl;
    cout<<"2-Crear usuario"<<endl;
    cout<<"3-Salir"<<endl;
    cout<<"Opcion:";
    cin>> valor;
        
    switch (valor)
    {
    case 1:
    VerificarUsuario(usuario);
    
    break;
        
    case 2:
    cout<<"Creando usuario"<<endl;
    usuario = CrearUsuario();
    return Login(usuario);
    
    break;
    
        case 3:
            return;
        break;
        }
}

void CambiarContraseña(Usuario usuario){
    string nuevaContraseña;
    do{
    cout<<"--Ingrese su nueva contrasena"<<endl;
    cin>> nuevaContraseña;
    usuario.Contraseña = nuevaContraseña;

    if (ValidarContrasena(usuario.Contraseña)) {
        cout << "Contrasena valida." <<endl;
        cout <<"Usuario: " << usuario.Nombre << " Cambio su contrasena a: " << usuario.Contraseña <<endl;
      return;
    } else {
        cout << "La contrasena debe tener al menos 1 mayuscula y 2 simbolos especiales." << endl;
        cout<<"--intente de nuevo--"<<endl;
    }
}

while (ValidarContrasena);
}

void MenuSistema(Usuario usuario){
    int valor;
    cout<<"--Ingrese su opcion: "<<endl;
    cout<<"1.Cambiar de Contrasena "<<endl;
    cout<<"2.Salir"<<endl;
    cout<<"Opcion:";
    cin>>valor;

    switch (valor)
    {
    case 1:
        CambiarContraseña(usuario);
        Login(usuario);
        break;

    case 2:
    cout<<"Adios..."<<endl;
    Login(usuario);
    return;
        break;
    }
}


int main() {

    Usuario usuarioPruebas;
    usuarioPruebas.Nombre = "franko";
    usuarioPruebas.Contraseña = "Franko12#";

    Producto producto;
    producto.id = 1;
    producto.Nombre = "Lavandinax1L";
    producto.Precio = 875.25;
    producto.Stock = 3000;

    Producto producto2;
    producto2.id = 4;
    producto2.Nombre = "Detergentex500ml";
    producto2.Precio = 1102.45;
    producto2.Stock = 2010;

    Producto producto3;
    producto3.id = 22;
    producto3.Nombre = "Jabon en polvo x250g";
    producto3.Precio = 650.22;
    producto3.Stock = 407;

    Producto productos[3] = {producto,producto2,producto3};
    Listar(productos);

    Login(usuarioPruebas);

    return 0;
}