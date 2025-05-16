#include<iostream>
using namespace std;

struct Usuario {
    int id;
    string Nombre;
    string Contraseña;
    string Categoria;
};

struct Producto {
    int id;
    string Nombre;
    double Precio;
    int Stock;
};

const int MAX_USUARIOS = 20;
int contadorUsuarios  = 4;

const int MAX_PRODUCTOS = 10;
int contadorProductos = 3;


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

void ComprarProducto(Producto productos[]) {
    ListarProductos(productos);
    int id;
    cout << "Ingrese el ID del producto que desea comprar: ";
    cin >> id;

    for (int i = 0; i < contadorProductos; i++) {
      if (productos[i].id == id) {
        cout << "Producto comprado" << endl;
        cout <<"Nombre: "<< productos[i].Nombre << endl;
        cout <<"Stock: "<< productos[i].Stock << endl;
        cout << "------------------------" << endl;

      if (productos[i].Stock > 0) {
        --productos[i].Stock;
        cout << "Stock actual: " << productos[i].Stock << endl;
    } else {
        cout << "Producto sin stock disponible." << endl;
            }
    return;
    }
}

    cout << "Producto con ID " << id << " no encontrado." << endl;
}


void MenuProductos(Producto productos[]){
    int opcion;
    do{
    cout<<"--Menu de articulos"<<endl;
    cout<<"1=Listar articulos"<<endl;
    cout<<"2=Nuevo articulo"<<endl;
    cout<<"3=Editar articulo"<<endl;
    cout<<"4=Eliminar articulo"<<endl;
    cout<<"5=Comprar articulo"<<endl;
    cout<<"6=Salir"<<endl;
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
    ComprarProducto(productos);
        break;

    case 6:
    return;
        break;
    }
}while (opcion != 6);

}

void MenuSistema(Usuario usuario[],Producto productos[]);

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

void CrearUsuario(Usuario usuario[]){
    do{
    cout<<"--Ingrese Nombre de su usuario "<<endl;
    cin>>usuario[contadorUsuarios].Nombre;
    cout<<"--ingrese Contrasena de su nuevo usuario: " <<endl;
    cin>>usuario[contadorUsuarios].Contraseña;
    cout<<"--ingrese la categoria de su nuevo usuario: " <<endl;
    cin>>usuario[contadorUsuarios].Categoria;

    if (ValidarContrasena(usuario[contadorUsuarios].Contraseña)) {
        cout << "Contrasena valida." << endl;
    ++contadorUsuarios;
        return;
    } else {
        cout << "La contrasena debe tener al menos 1 mayuscula y 2 simbolos especiales." << endl;
        cout<<"--intente de nuevo--"<<endl;
    }
}
while (ValidarContrasena);


    return;
};

void VerificarUsuario(Usuario usuario[],Producto productos[]) {

    cout<<"--Ingrese su contrasena"<<endl;
    string contraseña;
    for(int i = 0; i<3 ;i++){
    cin>>contraseña;

    for(int i = 0; i < contadorUsuarios;i++){
    if(usuario[i].Contraseña == contraseña){
        cout<<"Bienvenido: "<< usuario[i].Nombre<<endl;
        MenuSistema(usuario,productos);
        return;
        }
      }
      cout<<"Intente de nuevo, 'usuario'-_-"<<endl;
    }
    cout<<"BLOQUEADO"<<endl;
 }

void Login(Usuario usuario[],Producto productos[]){
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
    CrearUsuario(usuario);
    return Login(usuario,productos);
    
    break;
    
        case 3:
            return;
        break;
        }
}

void CambiarContraseña(Usuario usuario[]){
    int id;
    string nuevaContraseña;
    bool encontrado = false;

    do{
    cout<<"ingrese el id"<<endl;
    cin>>id;
    for(int i = 0;i < contadorUsuarios;i++){
    if(usuario[i].id == id){
        encontrado = true;
    while (true) {
                cout << "Ingrese su nueva contrasena: ";
                cin >> nuevaContraseña;
                if (ValidarContrasena(nuevaContraseña)) {
                    usuario[i].Contraseña = nuevaContraseña;
                    cout << "Contrasena actualizada correctamente.\n";
                    return;
                } else {
                    cout << "La contrasena debe tener al menos 1 mayuscula, 1 simbolo especial y entre 8 y 16 caracteres.\n";
                }
            }
        }
    }

    if (!encontrado) {
        cout << "ID incorrecto.\n";
    }
}

while (ValidarContrasena);
}

void MenuSistema(Usuario usuario[],Producto productos[]){
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
    usuarioPruebas.id = 1;
    usuarioPruebas.Nombre = "franko";
    usuarioPruebas.Contraseña = "Franko12#";
    usuarioPruebas.Categoria = "Administrador";

    Usuario usuarioPruebas2;
    usuarioPruebas2.id = 2;
    usuarioPruebas2.Nombre = "tomas";
    usuarioPruebas2.Contraseña = "Tomass12#";
    usuarioPruebas2.Categoria = "Cliente";

    Usuario usuarioPruebas3;
    usuarioPruebas3.id = 3;
    usuarioPruebas3.Nombre = "jose";
    usuarioPruebas3.Contraseña = "Josenose12#";
    usuarioPruebas3.Categoria = "Vendedor";

    Usuario usuarioPruebas4;
    usuarioPruebas4.id = 4;
    usuarioPruebas4.Nombre = "rodolfo";
    usuarioPruebas4.Contraseña = "Rodolfo12#";
    usuarioPruebas4.Categoria = "Deposito";
    
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

    Usuario usuarios[MAX_USUARIOS] = {usuarioPruebas,usuarioPruebas2,usuarioPruebas3,usuarioPruebas4};
    Producto productos[3] = {producto,producto2,producto3};

    Login(usuarios,productos);

    return 0;
}