n = int(input())
s = input()
cnt = s.count('R') * s.count('G') * s.count('B')
for i in range(n):
    for j in range(i + 1, n):
        k = 2*j - i
        if j < k < n and len({s[i], s[j], s[k]}) == 3:
            cnt -= 1
print(cnt)