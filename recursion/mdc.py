def mdc (a, b):
    if a % b == 0: return b
    return mdc(b, a%b)

print(mdc(10, 3)) #1