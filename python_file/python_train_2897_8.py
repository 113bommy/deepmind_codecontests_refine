import sys
input = sys.stdin.readline
n = int(input())
a = [list(input().rstrip()) for i in range(n)]
ans = 0
for k in range(n):
    for i in range(n):
        for j in range(i+1,n):
            if a[(i+k)%n][j] != a[(j+k)%n][i]:
                break
        else:
            continue
        break
    else:
        ans += n
print(ans)