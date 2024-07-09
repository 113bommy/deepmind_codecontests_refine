import sys
sys.setrecursionlimit(10000000)
MOD = 10 ** 9 + 7
INF = 10 ** 15

class SegmentTree():
   
    def __init__(self,N,f,unit):
        self.f = f
        self.unit = unit
        self.N = N
        self.tree = [self.unit] * (2*self.N)
        #self._build(array)
    
    def _build(self,array):
        for i,x in enumerate(array,self.N):
            self.tree[i] = x
        for i in range(self.N - 1,0,-1):
            self.tree[i] = self.f(self.tree[i << 1],self.tree[i << 1|1])
    
    def update(self,k,x):
        k += self.N
        self.tree[k] = x
        while k > 1:
            k >>= 1
            self.tree[k] = self.f(self.tree[k << 1],self.tree[k << 1|1])
    
    def query(self,l,r):
        l += self.N
        r += self.N
        vl = self.unit
        vr = self.unit
        while l < r:
            if l&1: 
                vl = self.f(vl,self.tree[l])
                l += 1
            if r&1:
                r -= 1
                vr = self.f(self.tree[r],vr)
            l >>= 1
            r >>= 1
        return self.f(vl,vr)
    
    def debug(self):
        print(self.tree)

def main():
    N = int(input())
    A = list(map(int,input().split()))

    st = SegmentTree(N,max,-1)
    L = [-1] * N
    for i,a in enumerate(A):
        L[i] = st.query(0,a - 1)
        st.update(a - 1,i)
    
    st = SegmentTree(N,min,N)
    R = [N] * N
    for i in range(N - 1,-1,-1):
        R[i] = st.query(0,A[i] - 1)
        st.update(A[i] - 1,i)
    
    ans = sum((R[i] - i)*(i - L[i])*A[i] for i in range(N))
    print(ans) 
if __name__ == '__main__':
    main()