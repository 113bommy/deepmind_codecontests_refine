S = input()
C = {"a": 0, "b": 0, "c": 0}
for s in S:
    C[s] += 1
if abs(C["a"] - C["b"]) <= 1 and abs(C["b"] - C["c"]) <= 1 and abs(C["c"] - C["a"]) <= 1:
    print("YES")
else:
    print("NO")
