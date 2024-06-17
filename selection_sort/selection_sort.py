def buscaMenor(arr):
    menor = arr[0]
    menor_index = 0
    for i in range (1, len(arr)):
        if arr[i] < menor:
            menor = arr[i]
            menor_index = i
    return menor_index

def selection_sort(arr):
    novoArr = []
    for i in range(len(arr)):
        menor = buscaMenor(arr)
        novoArr.append(arr.pop(menor))
    return novoArr

print(selection_sort([5,3,6,2,10]))