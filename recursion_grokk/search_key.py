'''
def search_key(main_box):
    pile = main_box.create_a_pile_4_search()
    while pile is not empty:
        box = pile.get_box()
        for item in box:
            if item.is_a_box():
                pile.append(item)
            elif item.is_a_key():
                print("found the key!")
                '''

def search_box(box):
    for item in box:
        if item.is_a_box():
            search_box(item)
        elif item.is_a_key():
            print("found the key")





            