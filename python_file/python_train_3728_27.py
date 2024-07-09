X, Y, Z, K = list(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

ab = []
for i in A:
  for j in B:
    ab.append(i + j)

ab.sort(reverse = True)

abc = []
for i in ab[:3000]:
  for j in C:
    abc.append(i + j)

abc.sort(reverse = True)

for i in range(K):
  print(abc[i])
