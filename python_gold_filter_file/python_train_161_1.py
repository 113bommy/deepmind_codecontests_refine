d = {
    '0': 1,
    '1': 0,
    '2': 0,
    '3': 0,
    '4': 1,
    '5': 0,
    '6': 1,
    '7': 0,
    '8': 2,
    '9': 1,
    'a': 1,
    'b': 2,
    'c': 0,
    'd': 1,
    'e': 0,
    'f': 0,
}
print(sum(d[c] for c in hex(int(input()))[2:]))
