
export class UserService {
  async getUsers() {
    return fetch("https://jsonplaceholder.typicode.com/users").then(r => r.json());
  }
  async getUserById(id) {
    return fetch(`https://jsonplaceholder.typicode.com/users/${id}`).then(r => r.json());
  }
}
