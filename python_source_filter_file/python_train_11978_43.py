W, H, r, x, y = map(int, input().split())
if r <= x <= W - r and r <= y <= H - r:
    print("Yes")
else:
    print("No")