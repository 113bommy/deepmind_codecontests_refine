n = int(input())

L = input().split(" ")
L=list(map(int,L))
i = 0
c = 0
p = 0
while i < n:
    if L[i] > p:
        p = L[i]

    if i == (p - 1):
        c+=1
    i+=1
print(c)