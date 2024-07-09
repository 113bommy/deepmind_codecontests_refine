from bisect import bisect_left

class SegmentTree:
    def __init__(self, N):
        self.N = 2 * pow(2, N.bit_length()) - 1
        self.data = [0 for _ in range(2*self.N)]
    
    def update(self, k, x):
        k += self.N-1
        self.data[k] = x
        while k >= 0:
            k = (k - 1) // 2
            self.data[k] = sum([self.data[2*k+1], self.data[2*k+2]])
    
    # [l,r)
    def query(self, l, r):
        L = l + self.N
        R = r + self.N
        s = 0
        while L < R:
            if R & 1:
                R -= 1
                s = sum([s, self.data[R-1]])
            if L & 1:
                s = sum([s, self. data[L-1]])
                L += 1
            L >>= 1; R >>= 1
        return s

    def node(self, k):
        return st.query(k, k+1)

def compress(arr):
    N = len(arr)
    narr = sorted(arr)
    pressed = [-1] * N
    for i in range(N):
        pressed[i] = bisect_left(narr, arr[i])
    return pressed
    

def accmulate(arr):
    N = len(arr)
    cs = [0]*(N+1)
    for i in range(N):
        cs[i+1] = cs[i] + arr[i]
    return cs

# [l,r)
def query(cs, l, r):
    return cs[r] - cs[l]

N, K = map(int,input().split())
A = [int(input()) - K for _ in range(N)]

cs = accmulate(A)
cs = compress(cs)
st = SegmentTree(N)

ans = 0

for i in range(N+1):
    ans += st.query(0, cs[i] + 1)
    st.update(cs[i], st.node(cs[i]) + 1)

print(ans)