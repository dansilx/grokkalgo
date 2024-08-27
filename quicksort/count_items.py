def count_items(array):
    if array == []:
        return 0
    else:
        return 1 + count_items(arr[1:])
    


array = [3, 7, 2, 9, 4]
result = count_items(array)
print(result)