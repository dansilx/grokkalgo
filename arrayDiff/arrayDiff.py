def arrayDiff(a, b):
    diff = []
    for num in a:
        if num not in b:
            diff.append(num)
    return diff