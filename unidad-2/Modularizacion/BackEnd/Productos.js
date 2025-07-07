
export class Producto{
    constructor(id, nombre, precio, stock){
        this.id = id;
        this.Nombre = nombre;
        this.Precio = precio;
        this.Stock = stock;
    }

imprimirDatos() {
    console.log(`ID: ${this.id} | Nombre: ${this.Nombre} | Precio: $${this.Precio} | Stock: ${this.Stock}`);
    }

comprarProducto() {
        if (this.Stock > 0) {
          this.Stock--;
          console.log(` Compraste: ${this.Nombre}\nStock restante: ${this.Stock}`);
        } else {
          console.log(" No hay stock disponible.");
        }
      } 

modificarProducto(nuevoNombre, nuevoPrecio, nuevoStock) {
    this.Nombre = nuevoNombre;
    this.Precio = nuevoPrecio;
    this.Stock = nuevoStock;
    console.log(" Producto modificado correctamente.");
    }

}
