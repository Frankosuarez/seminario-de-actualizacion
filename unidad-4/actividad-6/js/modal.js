 
 class UserModal extends HTMLElement {
  constructor() {
    super();
    this.style.display = "none";
    this.classList.add("w3-modal");
  }

  connectedCallback() {
    this.innerHTML = `
      <div class="w3-modal-content w3-card-4 w3-animate-top" style="max-width:600px; margin:auto; top:50%; transform:translateY(-50%)">
        <header class="w3-container w3-teal">
          <span class="w3-button w3-display-topright">&times;</span>
          <h2>Detalle de Usuario</h2>
        </header>
        <div class="w3-container modal-content"></div>
        <footer class="w3-container w3-teal">
          <p>Información extendida</p>
        </footer>
      </div>
    `;
    this.querySelector("span").addEventListener("click", () => this.hide());
  }

  show(contentHtml) {
    this.querySelector(".modal-content").innerHTML = contentHtml;
    this.style.display = "block";
  }

  hide() {
    this.style.display = "none";
  }
}

customElements.define("user-modal", UserModal);
