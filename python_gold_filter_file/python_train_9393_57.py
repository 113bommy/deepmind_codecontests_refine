for _ in range (int(input())):
    n = int(input())
    s = ""
    if n == 1:
        print(-1)
    else:
        s += "5" * (n - 1)
        print(s + '4')