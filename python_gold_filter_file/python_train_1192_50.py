klava = 'qwertyuiopasdfghjkl;zxcvbnm,./'
if input() == 'R':
    s = input()
    sr = ''
    for i in range(len(s)):
        sr += klava[klava.find(s[i]) - 1]
    print(sr)
else:
    s = input()
    sl = ''
    for i in range(len(s)):
        sl += klava[klava.find(s[i]) + 1]
    print(sl)
