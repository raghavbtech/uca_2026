const worker = new Worker("worker.js");

    worker.postMessage("start");

    worker.onmessage = function(e) {
        const usersDiv = document.getElementById("users");

        if (Array.isArray(e.data)) {
            e.data.forEach(user => {
                usersDiv.innerHTML += `${user.firstName} - ${user.active ? "Active" : "Inactive"}<br>`;
            });
        } else {
            usersDiv.innerHTML = e.data;
        }
    };