n = int(input())
h = []
for i in range(n):
    h.append(int(input()))
c = 0
t = 0
for i in h:
    t = abs(c-i)
    c = i
print(t)
