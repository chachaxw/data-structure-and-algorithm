function requestWithRetry1(url, attempts = 3) {
    return new Promise(function (resolve, reject) {
        fetch(url)
            .then(function (result) {
                resolve(result);
            })
            .catch(function (error) {
                attempts--; // 2, 1, 0

                if (attempts === 0) {
                    reject(error);
                } else {
                    setTimeout(() => {
                        requestWithRetry1(url, attempts);
                    }, 3000);
                }
            });
    });
}

async function requestWithRetry2(url, attempts = 3) {
    const retry = async (attempt = 1) => {
        try {
            return await fetch(url);
        } catch (error) {
            if (attempt >= attempts) {
                throw error;
            }

            // Use an increasing delay to prevent flodding the
            // server with requests in case of a short downtime.
            const delay = 1000 * attempt;

            return new Promise((resolve) =>
                setTimeout(() => resolve(retry(attempt + 1)), delay)
            );
        }
    };

    return retry;
}
