
class Component extends HTMLElement
{
    constructor()
    {
        super()

        this.btn = document.createElement("button");
        this.table = document.createElement("table");

        this.btn.innerText = "efectuar solicitud";

        this.appendChild(this.btn);
        this.appendChild(this.table);

    }

    pedirDatos()
    {
        fetch("https://jsonplaceholder.typicode.com/posts")
        .then(response =>
        {
            return response.json();
        }).then(data =>
        {
            let filaCabecera = document.createElement("tr");
            let idCabecera = document.createElement("th");
            let tituloCabecera = document.createElement("th");
            let bodyCabecera = document.createElement("th");

            idCabecera.innerText = "ID";
            tituloCabecera.innerText = "TITULO";
            bodyCabecera.innerText = "BODY"

            filaCabecera.appendChild(idCabecera);
            filaCabecera.appendChild(tituloCabecera);
            filaCabecera.appendChild(bodyCabecera);

            this.table.appendChild(filaCabecera);



            data.forEach(postObj => 
            {
                const fila = document.createElement("tr");

                const id = document.createElement("td");
                id.innerText = postObj.id;

                const titulo = document.createElement("td");
                titulo.innerText = postObj.title;

                const body = document.createElement("td");
                body.innerText = postObj.body;

                fila.appendChild(id);
                fila.appendChild(titulo);
                fila.appendChild(body);

                this.table.appendChild(fila);
                
            });

        })
    }

    connectedCallback()
    {
        this.btn.onclick = this.pedirDatos.bind(this);
    }
}

customElements.define("tabla-component", Component);

function main()
{
    let ej = new Component();
    document.body.appendChild(ej);
}

window.onload = main;