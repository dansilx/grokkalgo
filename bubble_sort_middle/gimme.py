def gimme(arr):
    sorted = list(arr) # guarda a array em uma variavel
    for i in range(0, len(sorted)):
        for j in range(i+1, len(sorted)):
            if sorted[i] > sorted[j]:
                temp = sorted[i]
                sorted[i] = sorted[j]
                sorted[j] = temp
    mid = sorted[1]
    for i in range(len(arr)):
        if arr[i] == mid:
            return i
