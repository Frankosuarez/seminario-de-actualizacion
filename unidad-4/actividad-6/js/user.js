
export class UserService {
  constructor(baseUrl) {
    this.baseUrl = baseUrl;
  }

  async getUsers() {
    const res = await fetch(`${this.baseUrl}/users`);
    return res.json();
  }

  async getUserById(id) {
    const res = await fetch(`${this.baseUrl}/users/${id}`);
    return res.json();
  }
}
