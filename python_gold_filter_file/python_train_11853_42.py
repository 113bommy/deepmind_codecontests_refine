H, W = map(int, input().split())
a = [input()for _ in range(H)]
print("#"*(W+2))
for r in a:
    print("#"+r+"#")
print("#"*(W+2))