for _ in range(int(input())):
    n, p, k = map(int, input().split())
    u = [0] + list(map(int, input().split()))
    a = [0] * (n + 1)
    c = [0] * (n + 1)
    u.sort()
    for i in range(1, n + 1):
        if i < k or u[i] > p:
            if u[i] + c[i - 1] > p:
                c[i] = c[i - 1]
                a[i] = a[i - 1]
            else:
                c[i] = c[i - 1] + u[i]
                a[i] = a[i - 1] + 1
        else:
            L = 0
            R = i - k + 1
            M = 0
            while R - L > 1:
                M = (R + L) // 2
                if c[M] > p - u[i]:
                    R = M
                else:
                    L = M
            if a[i - 1] > a[L] + k:
                a[i] = a[i - 1]
                c[i] = c[i - 1]
            else:
                a[i] = a[L] + k
                c[i] = c[L] + u[i]
    print(a[-1])






                
