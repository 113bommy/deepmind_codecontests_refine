X,Y,Z,K = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))
AB = []
ABC = []
for i in A:
    for j in B:
        AB.append(i+j)
AB.sort(reverse = True)
for i in AB[:K+1]:
    for j in C:
        ABC.append(i+j)
ABC.sort(reverse = True)
for i in range(K):
    print(ABC[i])