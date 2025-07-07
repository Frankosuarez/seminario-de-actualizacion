
export class Usuario {
  constructor(id, nombre, contraseña, categoria) {
    this.id = id;
    this.Nombre = nombre;
    this.Contraseña = contraseña;
    this.Categoria = categoria;
  }


esMayuscula(c) {
      return c >= 'A' && c <= 'Z';
    }

esSimboloEspecial(c) {
      return "!@#$%^&*()-_+=<>?/".includes(c);
    }

validarContraseña(contraseña) {
      let tieneMayuscula = false;
      let tieneSimbolo = false;
      let cantidad = contraseña.length >= 8 && contraseña.length <= 16;

      for (let c of contraseña) {
        if (this.esMayuscula(c)) tieneMayuscula = true;
        if (this.esSimboloEspecial(c)) tieneSimbolo = true;
      }

      return tieneMayuscula && tieneSimbolo && cantidad;
    }

 cambiarContraseña(nuevaContraseña) {
    if (this.validarContraseña(nuevaContraseña)) {
      this.Contraseña = nuevaContraseña;
      console.log("Contraseña actualizada correctamente.");
    } else {
      console.log("La nueva contraseña no cumple los requisitos.");
    }
  }

  modificarUsuario(nombre, contraseña, categoria) {
    this.Nombre = nombre;
    if (this.validarContraseña(contraseña)) {
      this.Contraseña = contraseña;
    }
    this.Categoria = categoria;
  }

}
