N=int(input())
H=tuple(map(int,input().split()))
A=tuple(map(int,input().split()))
class SegTreeMax:
    def __init__(self,N):
        self.N0=2**(N-1).bit_length()
        self.INF=2**63-1
        self.data=[-self.INF]*(2*self.N0)
        self.d=[0]*N
    def update(self,i,x):
        self.d[i]=x
        i+=self.N0-1
        self.data[i]=x
        while i>0:
            i=(i-1)//2
            self.data[i]=max(self.data[i*2+1],self.data[i*2+2])
    def max(self,l,r):
        L = self.N0 + l; R = self.N0 + r
        s = -self.INF
        while L < R:
            if R & 1:
                R -= 1
                s = max(s, self.data[R-1])
            if L & 1:
                s = max(s, self.data[L-1])
                L += 1
            L >>= 1; R >>= 1
        return s
s=SegTreeMax(N+1)
s.update(0,0)
for i,h in enumerate(H):
    m=s.max(0,h)
    s.update(h,m+A[i])
print(s.max(0,N+1))