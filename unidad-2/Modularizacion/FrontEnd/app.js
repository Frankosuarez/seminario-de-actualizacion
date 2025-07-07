import { Usuario } from '../BackEnd/Usuario.js';
import { Producto } from '../BackEnd/Productos.js';

export class App{
  constructor(usuarios, productos){
    this.usuarios = usuarios;
    this.productos = productos;
  }

  listarProductos(){
    for(let i = 0; i < this.productos.length ; i++){
      this.productos[i].imprimirDatos();
    }
  }

    menuProductos() {
      let opcion;
      do {
        opcion = prompt(
          "Menú de Productos:\n1. Listar\n2. Crear\n3. Modificar\n4. Eliminar\n5. Comprar\n6. Salir"
        );
        switch (opcion) {
          case "1": this.listarProductos(); break;

          case "2":
            let nombre = prompt("Nombre del producto:");
            let precio = parseFloat(prompt("Precio del producto:"));
            let stock = parseInt(prompt("Cantidad en stock:")); 
            
           let nuevoProducto = new Producto(this.productos.length, nombre, precio, stock);
           this.productos.push(nuevoProducto);

          break;

          case "3":
            let id3 = parseInt(prompt("ID del producto a modificar:"));
                for(let i = 0; i < this.productos.length; i++){
                    if(this.productos[i].id == id3){

                        let nuevoNombre = prompt("Nuevo nombre:");
                        let nuevoPrecio = parseFloat(prompt("Nuevo precio:"));
                        let nuevoStock = parseInt(prompt("Nuevo stock:")); 
                        this.productos[i].modificarProducto(nuevoNombre, nuevoPrecio, nuevoStock);
                        break; 

                    }
            }
        
          break;

          case "4":
            let id4 = parseInt(prompt("ID del producto a eliminar:"));
            for(let i = 0; i < this.productos.length; i++){
                    if(this.productos[i].id == id4){

                        this.productos.splice(i, 1); 
                        break;

                    }
            }

          break;

          case "5":
            this.listarProductos();
            let id5 = parseInt(prompt("Ingrese el ID del producto a comprar:")); 
            for(let i = 0; i < this.productos.length; i++){
                    if(this.productos[i].id == id5){

                        this.productos[i].comprarProducto(); 
                        break;

                    }
            }
          break;
        }
      } while (opcion !== "6");
    }

    menuCliente() {
      let opcion;
      do {
        opcion = prompt("Menú Cliente:\n1. Comprar producto\n2. Salir");
        if (opcion === "1"){ 
            this.listarProductos();
            let id = parseInt(prompt("Ingrese el ID del producto a comprar:")); 
            for(let i = 0; i < this.productos.length; i++){
                    if(this.productos[i].id == id){

                        this.productos[i].comprarProducto(); 
                        break;

                    }
              }
        }

      } while (opcion !== "2");
    }

     menuAdmin() {
      let opcion;
      do {
        opcion = prompt(
          "Menú de Productos:\n1. Listar\n2. Crear\n3. Modificar\n4. Eliminar\n5. Modificar usuario\n6. Salir"
        );
        switch (opcion) {
          case "1": this.listarProductos(); break;

          case "2":
            let nombre = prompt("Nombre del producto:");
            let precio = parseFloat(prompt("Precio del producto:"));
            let stock = parseInt(prompt("Cantidad en stock:")); 
            
           let nuevoProducto = new Producto(this.productos.length, nombre, precio, stock);
           this.productos.push(nuevoProducto);

          break;

          case "3":
            let id3 = parseInt(prompt("ID del producto a modificar:"));
                for(let i = 0; i < this.productos.length; i++){
                    if(this.productos[i].id == id3){

                        let nuevoNombre = prompt("Nuevo nombre:");
                        let nuevoPrecio = parseFloat(prompt("Nuevo precio:"));
                        let nuevoStock = parseInt(prompt("Nuevo stock:")); 
                        this.productos[i].modificarProducto(nuevoNombre, nuevoPrecio, nuevoStock); 
                        break;

                    }
            }
        
          break;

          case "4":
            let id4 = parseInt(prompt("ID del producto a eliminar:"));
            for(let i = 0; i < this.productos.length; i++){
                    if(this.productos[i].id == id4){

                        this.productos.splice(i, 1); 
                        break;

                    }
            }

          break;

          case "5":
            let id5 = parseInt(prompt("Ingrese el ID del usuario a modificar:"));
            let nuevoNombre = prompt(`Ingrese su nuevo Nombre `);
            let nuevaContraseña = prompt(`Ingrese su nueva Contraseña `);
            let nuevaCategoria = prompt(`Ingrese su nueva Categoría `);
            
            for(let i = 0; i < this.usuarios.length; i++){
              if(id5 == this.usuarios[i].id){
                this.usuarios[i].modificarUsuario(nuevoNombre, nuevaContraseña, nuevaCategoria);
                break;
              }
            }
          break;
        }
      } while (opcion !== "6");
    }

    MenuSistema(usuario){
    console.log("--Menu del sistema");
    console.log("1.Cambiar de contraseña");
    console.log("2.Gestionar Productos");
    let opcion = prompt("opcion:");
    if(opcion === "1"){
        let nuevaContraseña = prompt(`Ingrese la nueva contraseña`);
        usuario.cambiarContraseña(nuevaContraseña);

    }else if(opcion === "2"){
      if (usuario.Categoria === "Cliente"){ this.menuCliente();return;}
      if(usuario.Categoria === "Administrador"){ this.menuAdmin();return;};
      if(usuario.Categoria === "Deposito"){ this.menuProductos(); return;};
      if(usuario.Categoria === "Vendedor") { this.menuProductos();return;};

    }else{
      console.log("opcion invalida");
    }
    }

    login(){
    let opcion;
    do{
    console.log("--Login");
    console.log("1.Ingresar al sistema");
    console.log("2.Crear Usuario");
    console.log("3.Salir");
    opcion = prompt("opcion:");
    
    if(opcion == "1"){
      let intentos = 3;
      while (intentos > 0) {
        let contraseña = prompt("Ingrese su contraseña:");
        for(let i = 0; i < this.usuarios.length; i++){
          if(contraseña == this.usuarios[i].Contraseña){
            this.MenuSistema(this.usuarios[i]);
            return;
          }
        }
        --intentos;
      }

      console.log(" Usuario bloqueado por intentos fallidos.");

    }else if(opcion == "2"){
        let nombre = prompt("Ingrese nombre de usuario:");
        let contraseña = prompt("Ingrese contraseña:");
        let categoria = "Cliente";
        
        let nuevoUsuario = new Usuario(this.usuarios.length, nombre, contraseña, categoria);
        if(nuevoUsuario.validarContraseña(contraseña)){
        this.usuarios.push(nuevoUsuario);

        }else {
          console.log("contraseña invalida...");
        }

    }else{
      console.log("opcion invalida");
    }

    }while(opcion !== "3" );
  }

}
