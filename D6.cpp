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

const int MAX_PRODUCTOS = 10;
int contadorProductos = 0;


void CrearProducto(Producto productos[]) {
    if (contadorProductos >= MAX_PRODUCTOS) {
        cout << "No se pueden agregar más productos. Stock lleno.\n";
        return;
    }

    Producto nuevoProducto;
    cout << "Introduzca el ID del producto: ";
    cin >> nuevoProducto.id;
    cout << "Introduzca el nombre del producto: ";
    cin.ignore(); // Limpia el buffer
    getline(cin, nuevoProducto.Nombre);
    cout << "Introduzca el precio del producto: ";
    cin >> nuevoProducto.Precio;
    cout << "Introduzca la cantidad en stock: ";
    cin >> nuevoProducto.Stock;

    productos[contadorProductos] = nuevoProducto;
    contadorProductos++;

    cout << "Producto agregado correctamente.\n";
    return;
}


void ListarProductos(const Producto productos[]) {
    if (contadorProductos == 0) {
        cout << "No hay productos registrados.\n";
        return;
    }

    cout << "\n--- Lista de Productos ---\n";
    for (int i = 0; i < contadorProductos; i++) {
        cout << "ID: " << productos[i].id << " | Nombre: " << productos[i].Nombre
             << " | Precio: $" << productos[i].Precio
             << " | Stock: " << productos[i].Stock << " unidades\n";
    }
}


void ModificarProducto(Producto productos[], int id) {
    for (int i = 0; i < contadorProductos; i++) {
        if (productos[i].id == id) {
            cout << "Nuevo nombre: ";
            cin.ignore();
            getline(cin, productos[i].Nombre);
            cout << "Nuevo precio: ";
            cin >> productos[i].Precio;
            cout << "Nueva cantidad en stock: ";
            cin >> productos[i].Stock;
            cout << "Producto actualizado correctamente.\n";
            return;
        }
    }
    cout << "Producto con ID " << id << " no encontrado.\n";
}


void EliminarProducto(Producto productos[], int id) {
    for (int i = 0; i < contadorProductos; i++) {
        if (productos[i].id == id) {
            for (int j = i; j < contadorProductos - 1; j++) {
                productos[j] = productos[j + 1]; // Mueve los productos hacia arriba
            }
            contadorProductos--; // Reduce la cantidad de productos
            cout << "Producto eliminado correctamente.\n";
            return;
        }
    }
    cout << "Producto con ID " << id << " no encontrado.\n";
}

void MenuProductos(Producto productos[]){
    int opcion;
    do{
    cout<<"--Menu de articulos"<<endl;
    cout<<"1=Listar articulos"<<endl;
    cout<<"2=Nuevo articulo"<<endl;
    cout<<"3=Editar articulo"<<endl;
    cout<<"4=Eliminar articulo"<<endl;
    cout<<"5=Salir"<<endl;
    cout<<"Ingrese su opcion:";
    cin>>opcion;

    switch (opcion)
    {
    case 1:
        ListarProductos(productos);
        break;
    
    case 2:
        CrearProducto(productos);
        break;

    case 3:
    cout<<"ingrese id"<<endl;
    int id1;
    cin>>id1;
        ModificarProducto(productos, id1);
        break;

    case 4:
    cout<<"ingrese id"<<endl;
    int id;
    cin>>id;
    EliminarProducto(productos,id);
        break;

    case 5:
    return;
        break;
    }
}while (opcion != 5);

}

void MenuSistema(Usuario usuario,Producto productos[]);

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

void VerificarUsuario(Usuario usuario,Producto productos[]) {

    cout<<"--Ingrese su contrasena"<<endl;
    string contraseña;
    for(int i = 0; i<3 ;i++){
    cin>>contraseña;


    if(usuario.Contraseña == contraseña){
        cout<<"Bienvenido: "<< usuario.Nombre<<endl;
        MenuSistema(usuario,productos);
        return;
    }
    else {
        cout<<"Intente de nuevo, 'usuario'-_-"<<endl;
        }
    }
    cout<<"BLOQUEADO"<<endl;
}

void Login(Usuario usuario,Producto productos[]){
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
    VerificarUsuario(usuario,productos);
    
    break;
        
    case 2:
    cout<<"Creando usuario"<<endl;
    usuario = CrearUsuario();
    return Login(usuario,productos);
    
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

void MenuSistema(Usuario usuario,Producto productos[]){
    int valor;
    cout<<"--Ingrese su opcion: "<<endl;
    cout<<"1.Cambiar de Contrasena "<<endl;
    cout<<"2.Gestionar Productos"<<endl;
    cout<<"3.Salir "<<endl;
    cout<<"Opcion:";
    cin>>valor;

    switch (valor)
    {
    case 1:
        CambiarContraseña(usuario);
        Login(usuario,productos);
        break;
    
    case 2:
    MenuProductos(productos);
    return;
        break;

    case 3:
    cout<<"Adios..."<<endl;
    Login(usuario,productos);
    return;
        break;
    }
}


int main() {

    Usuario usuarioPruebas;
    usuarioPruebas.Nombre = "franko";
    usuarioPruebas.Contraseña = "Franko12#";

    Producto productos[MAX_PRODUCTOS];

    Login(usuarioPruebas,productos);

    return 0;
}