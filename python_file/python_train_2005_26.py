def flip(l):
    ll = []
    for i in reversed(range(len(l))):
        ll.append((l[i] + 1) % 2)
    return ll

inp = lambda : map(int, list(input()))
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(inp())
    b = list(inp())
    #print(b)
    #print(flip(b))
    ans = []
    for i in reversed(range(n)):
        if a[i] != b[i]:
            ans = [i + 1, 1, i + 1] + ans
    print(len(ans), end = " ")
    for i in ans:
        print(i, end = " ")
    print()