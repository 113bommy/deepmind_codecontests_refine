a = input().split('wub')
new = ''
for i in range(0,len(a)):
    if a[i]=='':
        continue
    else:
        new = new + a[i] + ' '
print(new)
