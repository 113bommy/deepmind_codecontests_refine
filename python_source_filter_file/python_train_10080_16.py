s = input()
k = int(input())

sset = set()

for i in range(1, len(s)+1):
    sset |= set([s[j:j+i] for j in range(0, len(s))])

print(sorted(sset)[k-1])