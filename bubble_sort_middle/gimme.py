def gimme(arr):
    sorted = list(arr) # guarda a array em uma variavel
    for i in range(0, len(sorted)):  #loop que percorre o tamanho da array

        for j in range(i+1, len(sorted)): #loop que percorre uma posição a frente o tamanho da lista

            if sorted[i] > sorted[j]:   #condicional que verifica se o primeiro 
                                        #elemento do index é maior que o segundo elemento do index                 
                temp = sorted[i] #armazena o valor do maior
                sorted[i] = sorted[j] #injeta o valor do menor na posição do maior
                sorted[j] = temp #injeta o valor na segunda posição 
    mid = sorted[1] #
    for i in range(len(arr)):
        if arr[i] == mid:
            return i
