n = int(input())
b = bin(n)[2:]
while(len(b)<6):
    b = '0'+b
b = list(b)
b[5],b[1] = b[1],b[5]
b[2],b[3] = b[3],b[2]
s = ''
for i in b:
    s+=i
print(int(s,2))