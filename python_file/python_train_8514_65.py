S = input()
T = input()

length = len(S)

ans = 0
pre = -1

for t in T:
    x = S.find(t, pre+1, length)
    if x != -1:
        ans += x - pre
        pre = x
    else:
        x = S.find(t, 0, pre+1)
        if x != -1:
            ans += length + x - pre
            pre = x
        else:
            ans = -1
            break

print(ans)