n = int(input())
s = input()
cnt = 0
for i in range(1000):
    c = [str(i // 100), str((i // 10) % 10), str(i % 10)]
    t = 0
    for j in range(n):
        if s[j]==c[t]:
            t+=1
        if t==3:
            cnt+=1
            break
print(cnt)
