def solve():
    n, k = map(int, input().split())
    for i in range(k):
        print(chr(ord('a') + (i + 1) % k), end="")
    print("")


t = eval(input())
while t:
    solve()
    t -= 1

