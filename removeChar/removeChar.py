def remove_char(url):
    for i in range(len(url)):
        if url[i] == '#':
            return url[:i]
    return url

print(remove_char("www.codewars.com#about"))