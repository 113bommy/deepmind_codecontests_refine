while True:
    H, W = map(int, input().split())
    if W == 0 and H == 0:
        break
   for i in range(H):
        print ('#' * W)
    print()