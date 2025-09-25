
class Component extends HTMLElement {
      constructor() {
        super();
        this.btn = document.createElement("button");
        this.btn.innerText = "Efectuar Solicitud";
        this.appendChild(this.btn);

        this.txtArea = document.createElement("textarea");
        this.appendChild(this.txtArea);
      }

      PedirDatos()
      {
      let xhr = new XMLHttpRequest(); 

        xhr.onload = () => 
        {
          this.txtArea.value = xhr.responseText;
        }

        xhr.open("GET", "https://jsonplaceholder.typicode.com/posts/1", true);
        xhr.send();

      }

      connectedCallback()
      {
        this.btn.onclick = this.PedirDatos.bind(this);
      }


    }

    customElements.define("xhr-component", Component);


function main()
{
    let example = new Component();
    document.body.appendChild(example);

    
}

window.onload = main;