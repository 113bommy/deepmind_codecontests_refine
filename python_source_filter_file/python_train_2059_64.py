a,v = map(int, input().split())
b,w = map(int, input().split())
t=int(input())

rev = v-w
if rev*t >= (b-a):
    print("YES")
else:
    print("NO")