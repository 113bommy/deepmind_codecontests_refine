num = [[[0 for i in range(10)] for i in range(3)] for i in range(4)]

n = int(input())
for i in range(n):
    b, f, r, v = map(int, input().split())
    num[b-1][f-1][r-1] += v

for b in range(4):
    for f in range(3):
        print(" ".join(map(str, num[b][f])))
    if b < 3:
        print("#"*20)
