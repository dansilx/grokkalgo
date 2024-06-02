'''
def fib(n):
    print(f'fib({n})')
    if n <= 2: return 1
    return fib(n-1) + fib(n-2)

print(fib(13))

esse programa não é eficiente pois repete cálculos já calculados
'''
dic = {}
def fib(n):
    if n <= 2: return 1
    if n not in dic:
        dic[n] = fib(n-1) + fib(n-2)
    return dic[n]
print(fib(100)) #354224848179261915075