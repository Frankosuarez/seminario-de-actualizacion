import { Usuario } from "./BackEnd/Usuario.js";
import { Producto } from "./BackEnd/Productos.js";
import { App } from './FrontEnd/app.js';

export function main() {
  const user = new Usuario( 0, "franko", "Franko12#", "Administrador");
  const user1 = new Usuario( 1, "tomas", "Tomass12#", "Cliente");
  const user2 = new Usuario( 2, "jose", "Josenose12#", "Vendedor");
  const user3 = new Usuario( 3, "rodolfo", "Rodolfo12#", "Deposito");

  const producto = new Producto(0, "Lavandinax1L", 875.25, 3000 );
  const producto1 = new Producto(1, "Detergentex500ml", 1102.45, 2010 );
  const producto2 = new Producto(2, "Jabon en polvo x250g", 650.22, 407 );

  const usuarios = [ user, user1, user2, user3 ];
  const productos = [ producto, producto1, producto2 ];

  const app = new App(usuarios, productos);
  app.login();
}

main()