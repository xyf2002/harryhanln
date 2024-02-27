async function pl() {
	const promise1 = await new Promise((resolve, reject) => {
		setTimeout(() => {
			resolve('Success');
		}, 1000);
	}).then(() => {
		console.log("First then");
		setTimeout(() => {
		}, 1000);
	})
	console.log(promise1)
	return promise1
}

pl()
