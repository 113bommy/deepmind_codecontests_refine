s = input()
h = s[::2].count('1') + s[1::2].count('0')
print(min(h, len(s)-h))