def is_square(n):
    if n < 0:
        return False
    else:
        for i in range(n + 1):
            if i * i == n:
                return True
            elif i * i > n:
                return False
        return False