import {UserService} from "./user";
import {UserModal} from "./modal";
import {UserTable} from "./table";

function main()
{
    const service = new UserService("https://jsonplaceholder.typicode.com");
    const modal = new UserModal();
    customElements.define("user-table", class extends UserTable {
    constructor() {
        super(service, modal);
    }
    });

}

window.onload = main;
