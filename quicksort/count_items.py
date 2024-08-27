def count_items(array):
    if array == []:
        return 0
    
    return 1 + count_items(array[1:])
    


array = [3, 7, 2, 9, 4]
result = count_items(array)
print(result)