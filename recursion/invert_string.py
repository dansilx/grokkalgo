def inv(s):
    if len(s) <= 1: return s
    return inv(s[1:]) + s[0]

print(inv('banana')) #ananab