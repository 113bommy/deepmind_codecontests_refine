k = int(input())
if k == 0:
    print("1 1")
    print("300000")
else:
    print("3 2")
    a = int(1 << 17)
    print("%d %d" % (a + k, k))
    print("%d %d" % (a, a + k))
    print("%d %d" % (a , k))