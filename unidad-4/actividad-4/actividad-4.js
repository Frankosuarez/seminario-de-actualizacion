
class UserTable extends HTMLElement
{
    constructor()
    {
        super()
        
        this.btn = document.createElement("button");
        this.btn.innerText = "Efectuar Solicitud";
        this.btn.className = "w3-button w3-green w3-margin-bottom";

        this.table = document.createElement("table");
        this.table.className = "w3-table-all w3-card-4 w3-hoverable"

        this.tHeader = document.createElement("thead");
        this.tbody = document.createElement("tbody");

        this.header = document.createElement("tr");
        this.header.className = "w3-green";

        this.idHeader = document.createElement("th");
        this.nameHeader = document.createElement("th");
        this.usernameHeader = document.createElement("th");
        this.emailHeader = document.createElement("th");
        this.phoneHeader = document.createElement("th");
        this.websiteHeader = document.createElement("th");

        this.idHeader.innerHTML = "ID";
        this.nameHeader.innerHTML = "NAME";
        this.usernameHeader.innerHTML = "USERNAME";
        this.emailHeader.innerHTML = "EMAIL";
        this.phoneHeader.innerHTML = "PHONE";
        this.websiteHeader.innerHTML = "WEBSITE";

        this.header.appendChild(this.idHeader);
        this.header.appendChild(this.nameHeader);
        this.header.appendChild(this.usernameHeader);
        this.header.appendChild(this.emailHeader);
        this.header.appendChild(this.phoneHeader);
        this.header.appendChild(this.websiteHeader);

        this.tHeader.appendChild(this.header);
        this.table.appendChild(this.tHeader);
        this.table.appendChild(this.tbody);

        this.appendChild(this.btn);
        this.appendChild(this.table);
    }

    pedirDatos()
    {
        fetch("https://jsonplaceholder.typicode.com/users/")
        .then(response =>
        {
            return response.json();
        }
        ).then(data =>
        {
            data.forEach(obj => {

                console.log(obj);
                let row = document.createElement("tr");
                
                let id = document.createElement("td");
                let name = document.createElement("td");
                let username = document.createElement("td");
                let emailTag = document.createElement("span");
                let phone = document.createElement("td");
                let website = document.createElement("td");

                emailTag.className = "w3-tag w3-round w3-green";

                id.innerHTML = obj.id;
                name.innerHTML = obj.name;
                username.innerHTML = obj.username;
                emailTag.innerHTML = obj.email;
                phone.innerHTML = obj.phone;
                website.innerHTML = obj.website;

                row.appendChild(id);
                row.appendChild(name);
                row.appendChild(username);
                row.appendChild(emailTag);
                row.appendChild(phone);
                row.appendChild(website);

                this.tbody.appendChild(row);
                
            });
        }
        )
    }

    connectedCallback()
    {
        this.btn.onclick = this.pedirDatos.bind(this);
    }
}

customElements.define("user-table", UserTable);

function main()
{
    let ej = new UserTable();
    document.body.appendChild(ej);
}

window.onload = main;