n = int(input())
s = set()
ln = 0
for i in range(n):
    st = input()
    s.add(st)
    if ln != len(s):
        print('NO')
    else:
        print("YES")
    ln = len(s)
