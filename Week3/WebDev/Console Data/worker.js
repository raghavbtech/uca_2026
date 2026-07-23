self.onmessage = async function () {
    try {
        const response = await fetch("https://dummyjson.com/users");
        const user = await response.json();

        if (!user || user.length === 0) {
            throw new Error("No users returned");
        }

        user.users.forEach(user => {
            self.postMessage(
                `${user.firstName} - ${user.active ? "Active" : "Inactive"}`
            );
        });

    } catch (err) {
        self.postMessage("Error: " + err.message);
    }
};