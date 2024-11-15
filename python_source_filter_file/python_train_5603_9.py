N = int(input())

elem = [0 for _ in range(N+1)]

for i in range(1, N+1):
    cur = i
    for j in range(2, i+1):
        while cur % j == 0:
            elem[j] += 1
            cur //= j

def num(m):
    return len(list(filter(lambda x: x >= m-1, elem)))

print(num(75)  + num(25)*(num(3)-1) + num(15)*(num(3)-1) + num(5)*(num(5)-1)*(num(3)-2) // 2)
