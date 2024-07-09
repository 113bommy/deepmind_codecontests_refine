R = [0]*2019
s = input()

res = 0
for d in map(int, s):
    new = [0]*2019
    for i in range(2019):
        new[(i*10 + d)%2019] += R[i]
    new[d] += 1
    res += new[0]
    R = new
print(res)

