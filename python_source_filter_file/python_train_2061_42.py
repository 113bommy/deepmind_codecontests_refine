S = input()

odd = S[::2]
even = [1::2]

if 'L' in odd or 'R' in even:
    print('No')
else:
    print('Yes')