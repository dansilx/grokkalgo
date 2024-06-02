def dec2bin(n):
    if n == 0: return ''
    return dec2bin (n//2) + str(n%2)

print(dec2bin(18)) #10010