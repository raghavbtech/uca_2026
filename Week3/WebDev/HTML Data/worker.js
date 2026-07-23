self.onmessage = async function () {
    try {
        const response = await fetch("https://dummyjson.com/users");
        const user = await response.json();

        if (!user || user.length === 0) {
            self.postMessage("No users found");
            return;
        }

        self.postMessage(user.users);

    } catch (error) {
        self.postMessage("No users found");
    }
};