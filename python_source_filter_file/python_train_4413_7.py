n = int(input())
d = list(map(int, input().split()))
s, t = sorted(list(map(int, input().split())))
s -= 1
t -= 1
print(min(sum(d[s:t]), sum(d[s:t])) if s != t else '0')