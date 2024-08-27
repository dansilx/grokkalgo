def quicksort(array):
    if len(array) < 2:
        return array
    else:
        pivot = array[0]
        minor = [i for i in array[1:] if i <= pivot]
        major = [i for i in array[1:] if i > pivot]
        return quicksort(minor) + [pivot] + quicksort(major)
    

# def quicksort(array):
#     if len(array) < 2:
#         return array
#     else:
#         pivot = array[0]
#         minor = []
#         major = []

#         for i in array[1:]:
#             if i < pivot:
#                 minor.append(i)
#             else:
#                 major.append(i)

#         return quicksort(minor) + [pivot] + quicksort(major)
    
if __name__ == "__main__":
    print(quicksort([8, 17, 5, -1, 14, 6, 8, 9, 3]))