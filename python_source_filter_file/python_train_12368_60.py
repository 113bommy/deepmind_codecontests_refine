W,H,x,y = map(int, input().split())
print(W*H/2, 1 if W/2 == x or H/2 == y else 0)