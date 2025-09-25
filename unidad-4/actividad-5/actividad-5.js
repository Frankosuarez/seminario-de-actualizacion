
class UserTable extends HTMLElement {
      constructor() {
        super();

        this.btn = document.createElement("button");
        this.btn.innerText = "Efectuar Solicitud";
        this.btn.className = "w3-button w3-green w3-margin-bottom";

        this.table = document.createElement("table");
        this.table.className = "w3-table-all w3-card-4 w3-hoverable";

        this.thead = document.createElement("thead");
        this.headerRow = document.createElement("tr");
        this.headerRow.className = "w3-green";

        const headers = ["ID", "Usuario", "Nombre", "Correo", "Web", "Celular"];
        headers.forEach(h => {
          const th = document.createElement("th");
          th.innerText = h;
          this.headerRow.appendChild(th);
        });

        this.thead.appendChild(this.headerRow);

        this.tbody = document.createElement("tbody");

        this.table.appendChild(this.thead);
        this.table.appendChild(this.tbody);

        this.appendChild(this.btn);
        this.appendChild(this.table);

        this.modal = document.createElement("div");
        this.modal.className = "w3-modal";
        this.modal.innerHTML = `
          <div class="w3-modal-content w3-card-4 w3-animate-top" style="max-width:600px">
            <header class="w3-container w3-teal"> 
              <span class="w3-button w3-display-topright">&times;</span>
              <h2>Detalle de Usuario</h2>
            </header>
            <div class="w3-container" id="modal-content"></div>
            <footer class="w3-container w3-teal">
              <p>Información adicional</p>
            </footer>
          </div>
        `;
        document.body.appendChild(this.modal);

        // Cerrar modal
        this.modal.querySelector("span").onclick = () => {
          this.modal.style.display = "none";
        };
      }

      pedirDatos() {
        fetch("https://jsonplaceholder.typicode.com/users/")
          .then(response => response.json())
          .then(data => {
            this.tbody.innerHTML = "";
            data.forEach(obj => {
              let row = document.createElement("tr");

              row.innerHTML = `
                <td>${obj.id}</td>
                <td>${obj.username}</td>
                <td>${obj.name}</td>
                <td><span class="w3-tag w3-round w3-teal">${obj.email}</span></td>
                <td>${obj.website}</td>
                <td>${obj.phone}</td>
              `;

              row.onclick = () => this.mostrarDetalle(obj.id);

              this.tbody.appendChild(row);
            });
          });
      }

      mostrarDetalle(userId) {
        fetch(`https://jsonplaceholder.typicode.com/users/${userId}`)
          .then(response => response.json())
          .then(user => {
            const modalContent = this.modal.querySelector("#modal-content");
            modalContent.innerHTML = `
              <h3>${user.name} (${user.username})</h3>
              <p><b>Compañía:</b> ${user.company.name}<br>
                 <i>"${user.company.catchPhrase}"</i><br>
                 Sector: ${user.company.bs}</p>
              <p><b>Dirección:</b><br>
                 ${user.address.street}, ${user.address.suite}<br>
                 ${user.address.city} (${user.address.zipcode})</p>
              <p><b>Geo:</b> Lat: ${user.address.geo.lat}, Lng: ${user.address.geo.lng}</p>
            `;
            this.modal.style.display = "block";
          });
      }

      connectedCallback() {
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