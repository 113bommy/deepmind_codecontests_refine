s = input()
print('AC' if 'A' in s and 'C' in s[2:-1] and s[1:].replace('C','',1).islower() else 'WA')