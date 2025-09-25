
export class UserTable extends HTMLElement {
  constructor(service, modal) {
    super();
    this.service = service;
    this.modal = modal;

    this.btn = document.createElement("button");
    this.btn.innerText = "Efectuar Solicitud";
    this.btn.className = "w3-button w3-green w3-margin-bottom";

    this.table = document.createElement("table");
    this.table.className = "w3-table-all w3-card-4 w3-hoverable";

    this.appendChild(this.btn);
    this.appendChild(this.table);
  }

  async loadData() {
    const users = await this.service.getUsers();

    const header = this.table.createTHead();
    const row = header.insertRow();
    ["ID","Usuario","Nombre","Correo","Web","Celular"].forEach(h => {
      const th = document.createElement("th");
      th.innerText = h;
      th.className = "w3-green";
      row.appendChild(th);
    });

    users.forEach(user => {
      const tr = this.table.insertRow();
      tr.innerHTML = `
        <td>${user.id}</td>
        <td>${user.username}</td>
        <td>${user.name}</td>
        <td><span class="w3-tag w3-round w3-teal">${user.email}</span></td>
        <td>${user.website}</td>
        <td>${user.phone}</td>
      `;
      tr.onclick = async () => {
        const detail = await this.service.getUserById(user.id);
        this.modal.show(`
          <p><b>Dirección:</b> ${detail.address.street}, ${detail.address.city}</p>
          <p><b>Empresa:</b> ${detail.company.name}</p>
        `);
      };
    });
  }

  connectedCallback() {
    this.btn.onclick = () => this.loadData();
  }
}
