n, m, r = [int(t) for t in input().split(' ')]
s = [int(t) for t in input().split(' ')]
b = [int(t) for t in input().split(' ')]
print(max(r % min(s) + max(b) * (r // min(s)), r))
