n, k = map(int, input().split())

best = n*k+1
for ost in range(1, k):
    if n%ost==0:
        best = min(best, (n//ost)*k+ost)
print(best)
