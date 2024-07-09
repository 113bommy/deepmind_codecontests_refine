from collections import Counter

N = int(input())
As = list(map(int, input().split()))

cnt = Counter(As)
As.sort(reverse=True)

Ps = [2]
for i in range(58):
    Ps.append(Ps[-1] * 2)
Ps = Ps[::-1]

ans = 0
for A in As:
    if cnt[A] <= 0: continue
    cnt[A] -= 1
    for P in Ps:
        if cnt[P - A] > 0:
            ans += 1
            cnt[P - A] -= 1
            break
print(ans)
