ins = input().split()
a = int(ins[0])
b = int(ins[1])
n = int(input())
ins = list(map(int, input().split()))
minx = ((ins[0]-a)**2 + (ins[1]-b)**2)**(1/2) / ins[2]
for i in range(1,n):
    ins = list(map(int, input().split()))
    if (((ins[0]-a)**2 + (ins[1]-b)**2)**(1/2) / ins[2]) < minx:
        minx = ((ins[0]-a)**2 + (ins[1]-b)**2)**(1/2) / ins[2]
print(minx)