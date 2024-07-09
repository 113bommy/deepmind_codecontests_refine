n, m = map(int, input().split())
val = m//n
i = val
while i > 0 :
    if m % i == 0:
        print(i)
        exit()
    i -= 1