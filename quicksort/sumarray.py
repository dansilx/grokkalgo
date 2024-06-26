def sumarray(arr):
    #Caso base: se o array estiver vazio, a soma é 0
    if len(arr) == 0:
        return 0
    #Caso Base: se o array tiver um único elemento, a soma é esse elemento 
    elif len(arr) == 1:
        return arr[0]
    else: 
        #Encontrar o ponto médio do array
        mid = len(arr) // 2
        #Dividir o array em duas partes
        left =  arr[:mid]
        right =  arr[mid:]
        #Chamada recursiva para cada parte e soma os resultados 
        sumleft = sumarray(left) 
        sumright = sumarray(right)
        #Combinar resultados
        return sumleft + sumright
#exemplo de uso
array = [1, 2, 3, 4, 5]
res = sumarray(array)
print(res)