class SegT():
    def __init__(self, size):
        self.size = 1
        while self.size < size: self.size *= 2
        self.data = [0] * (self.size * 2 - 1)
    
    def update(self, i, x):
        i += (self.size - 1)
        self.data[i] = x
        while i > 0:
            i = (i - 1) // 2
            self.data[i] = self.data[i*2+1] | self.data[i*2+2]
        
    def get(self, a, b, node=0, l=0, r=-1):
        if r < 0: r = self.size
        if r <= a or b <= l: return 0
        if a <= l and r <= b: return self.data[node]
        vl = self.get(a, b, node*2+1, l, (l+r)//2)
        vr = self.get(a, b, node*2+2, (l+r)//2, r)
        return vl | vr

N = int(input())
S = input()
Q = int(input())

segt = SegT(N)
for i in range(N):
    x = ord(S[i]) - ord('a')
    segt.update(i, (1<<x))

for i in range(Q):
    t, l, r = input().split()
    if t == "1":
        x = ord(r) - ord('a')
        segt.update(int(l)-1, (1<<x))
    else:
        x = segt.get(int(l)-1,int(r))
        ans = 0
        for i in range(26):
            if x>>i&1: ans += 1
        print(ans)
