#include<iostream>
using namespace std;

struct Usuario {
    string Nombre;
    string Contraseña;
};

void MenuSistema(Usuario usuario);

Usuario CrearUsuario(){
    Usuario usuario;

    cout<<"--Ingrese Nombre de su usuario "<<endl;
    cin>>usuario.Nombre;
    cout<<"--ingrese Contrasena de su nuevo usuario: " <<endl;
    cin>>usuario.Contraseña;
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
    cout<<"--Ingrese su nueva contrasena"<<endl;
    cin>> nuevaContraseña;
    usuario.Contraseña = nuevaContraseña;
    cout<<"Contrasena cambiada a: "<<usuario.Contraseña<<endl;
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

    Login(usuarioPruebas);

    return 0;
}