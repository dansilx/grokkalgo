def regression(i):
    print(i)
    if i <= 1:
        return
    else:
        regression(i-1)
    
regression(11)