def sd(n):
    if n <= 9: return n
    return sd(n//10) + n % 10

print(sd(998)) #26