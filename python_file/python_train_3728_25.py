X, Y, Z, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
AB = []
for i in A:
    for j in B:
        AB.append(i + j)
AB = sorted(AB, reverse=True)[:K]
ABC = []
for i in AB:
    for j in C:
        ABC.append(i + j)

ABC = sorted(ABC, reverse=True)[:K]
for a in ABC:
    print(a)