import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(input()[:-1])
    b = list(input()[:-1])
    ans = []
    z = ["0" for i in range(n)]
    while a != z:
        if a[0] == "0":
            a[0] = "1"
            ans.append(1)
        else:
            for i in range(n-1, -1, -1):
                if a[i] == "0":
                    continue
                else:
                    ans.append(i+1)
                    for j in range(i+1):
                        if a[j] == "0":
                            a[j] = "1"
                        else:
                            a[j] = "0"
                    re = reversed(a[:i+1])
                    a[:i+1] = re
                    break
    while a != b:
        for i in range(n-1,-1,-1):
            if a[i] != b[i]:
                ans.append(i+1)
                for j in range(i + 1):
                    if a[j] == "0":
                        a[j] = "1"
                    else:
                        a[j] = "0"
                re = reversed(a[:i + 1])
                a[:i + 1] = re
                break

    print(len(ans), *ans)


