position = input()
if position in ['a1', 'a8', 'h1', 'h8']:
    print(3)
elif position[0] in ['1', '8'] or position[1] in  ['a', 'h']:
    print(5)
else:
    print(8)