N, M = map(int, input().split())
if M % N == 0:
    print(M // N)
    quit()
for i in range(M//N + 1):
    if M % (M//N-i) == 0:
        print(M//N-i)
        quit()