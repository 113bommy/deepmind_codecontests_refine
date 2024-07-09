N = int(input())
S = input()
ans = 0
for i in range(1000):
    cnt = 0
    n = str(i).zfill(3)
    for c in S:
        if c == n[cnt]:
            cnt += 1

        if cnt == 3:
            ans += 1
            break

print(ans) 
