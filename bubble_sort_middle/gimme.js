function gimme(arr) {
    let sorted = arr.slice()
    for (let i = 0; i < sorted.length; i++) {
        for (let j = i + 1; j < sorted.length; j++) {
            if (sorted[i] > sorted[j]) {
                let temp = sorted[i]
                sorted[i] = sorted[j]
                sorted[j] = temp
            }
        }
    }

    let mid = sorted[1]

    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === mid) {
            return i
        }
    }
}