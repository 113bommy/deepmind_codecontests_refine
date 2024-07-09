n = int(input())
v = sorted(list(map(int, input().split())))

result = list(v)

for i in range(n//2):
    #print(i*2+1, i)
    result[i*2+1] = v[i]
#print("--")
for i in range(n//2):
    #print(i*2, i+n//2)
    result[i*2] = v[i+n//2]

if len(result)%2==0:
    result[-1],result[-2]=result[-2],result[-1]

c = 0
for i in range(1,n-1):
    if result[i-1] > result[i] < result[i+1]:
        c += 1

print(c)
print(*result)
