N, A, B = map(int, input().split())

if ((B-A)%2 == 0):
    print((B-A)//2)
    exit()

print(min(A-1, N-B) + 1 + (B-A)//2)