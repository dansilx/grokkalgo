'''
código em haskell:

soma [] = 0
soma (x:xs) = x + (soma xs)

'''

def soma(lista):
    if not lista:
        return 0
    x = lista[0]
    xs = lista[1:]

    return x + soma(xs)

lista = [1,2,3,4,5]
res = soma(lista)
print("A soma dos elementos da lista é:", res)