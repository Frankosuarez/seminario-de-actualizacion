import { UserService } from "./user.js";
import "./modal.js";

 export class UserTable extends HTMLElement {
  constructor() {
    super();
    this.service = new UserService();

    // Botón para cargar la tabla
    this.btn = document.createElement("button");
    this.btn.textContent = "Efectuar Solicitud";
    this.btn.className = "w3-button w3-green w3-margin-bottom";


    this.table = document.createElement("table");
    this.table.className = "w3-table-all w3-card-4 w3-hoverable";
    this.tbody = document.createElement("tbody");

    const headers = ["ID", "Usuario", "Nombre", "Correo", "Web", "Celular"];
    const thead = document.createElement("thead");
    const row = document.createElement("tr");
    row.className = "w3-green";
    headers.forEach(h => {
      const th = document.createElement("th");
      th.textContent = h;
      row.appendChild(th);
    });
    thead.appendChild(row);

    this.table.appendChild(thead);
    this.table.appendChild(this.tbody);

    this.appendChild(this.btn);
    this.appendChild(this.table);
  }

  connectedCallback() {
    this.modal = document.querySelector("user-modal");

    this.btn.addEventListener("click", () => this.loadData());
  }

  async loadData() {
    const users = await this.service.getUsers();
    this.tbody.innerHTML = "";

    users.forEach(u => {
      const tr = document.createElement("tr");
      tr.innerHTML = `
        <td>${u.id}</td>
        <td>${u.username}</td>
        <td>${u.name}</td>
        <td><span class="w3-tag w3-round w3-teal">${u.email}</span></td>
        <td>${u.website}</td>
        <td>${u.phone}</td>
      `;
      tr.addEventListener("click", async () => {
        const detail = await this.service.getUserById(u.id);
        this.modal.show(`
          <h3>${detail.name} (${detail.username})</h3>
          <p><b>Correo:</b> ${detail.email}</p>
          <p><b>Teléfono:</b> ${detail.phone}</p>
          <p><b>Compañía:</b> ${detail.company.name}</p>
          <p><b>Dirección:</b> ${detail.address.street}, ${detail.address.city}</p>
          <p><b>Sitio Web:</b> ${detail.website}</p>
        `);
      });
      this.tbody.appendChild(tr);
    });
  }
}

customElements.define("user-table", UserTable);
