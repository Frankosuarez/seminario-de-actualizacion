
export class UserModal {
  constructor() {
    this.modal = document.createElement("div");
    this.modal.className = "w3-modal";
    this.modal.style.display = "none";
    this.modal.innerHTML = `
      <div class="w3-modal-content w3-card-4">
        <header class="w3-container w3-teal">
          <span id="closeModal" 
                class="w3-button w3-display-topright">&times;</span>
          <h2>Detalle Usuario</h2>
        </header>
        <div class="w3-container" id="modal-body"></div>
        <footer class="w3-container w3-teal">
          <p>Detalle adicional</p>
        </footer>
      </div>`;
    document.body.appendChild(this.modal);

    this.modal.querySelector("#closeModal").onclick = () => this.close();
  }

  show(contentHtml) {
    this.modal.querySelector("#modal-body").innerHTML = contentHtml;
    this.modal.style.display = "block";
  }

  close() {
    this.modal.style.display = "none";
  }
}