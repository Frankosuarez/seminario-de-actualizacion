

class Componente extends HTMLElement
{
    constructor()
    {
        super()

        this.btn = document.createElement("button");
        this.txtArea = document.createElement("textarea");

        this.btn.innerText = "efectuar solicitud";

        this.appendChild(this.btn);
        this.appendChild(this.txtArea);
    }

    pedirDatos()
    {
    fetch("https://jsonplaceholder.typicode.com/posts/1")
    .then(response =>
    {
        console.log(response);
        return response.text(); //.json si lo quiero hacer objeto
    }).then(data =>
    {
        console.log(data);
        //this.txtArea.value = JSON.stringify(data); si lo quiero usar como objeto
        this.txtArea.value = data; //copio y pego la respuesta del GET
    });

    }
    connectedCallback()
        {
            this.btn.onclick = this.pedirDatos.bind(this);
        }

}

customElements.define("fecth-component", Componente);

function main()
{
    let ej = new Componente();
    document.body.appendChild(ej);
}

window.onload = main;



