import sys
sys.setrecursionlimit(100000000)
input = sys.stdin.readline
MOD = 10 ** 9 + 7

class Matrix(list):

    def mul(self,B,mod = 0):
        C = Matrix([[0] * len(B[0]) for _ in range(len(self))])
        if mod == 0:
            for i in range(len(self)):
                for k in range(len(B)):
                    for j in range(len(B[0])):
                        C[i][j] += self[i][k] * B[k][j]
            
            return C
        else:
            for i in range(len(self)):
                for k in range(len(B)):
                    for j in range(len(B[0])):
                        C[i][j] = (C[i][j] + self[i][k] * B[k][j]) % mod
            
            return C

    
    def pow(self,n,mod = 0):
        if len(self) != len(self[0]):
            raise ValueError('the size of matrix is different')

        if mod == 0:
            B = Matrix([[0] * len(self) for _ in range(len(self))])
            A = self
            for i in range(len(self)):
                B[i][i] = 1
            
            while n > 0:
                if (n&1):
                    B = B.mul(A)
                A = A.mul(A)
                n //= 2
            
            return B

        else:
            B = Matrix([[0] * len(self) for _ in range(len(self))])
            A = self
            for i in range(len(self)):
                B[i][i] = 1
            
            while n > 0:
                if (n&1):
                    B = B.mul(A,mod)
                A = A.mul(A,mod)
                n //= 2
            
            return B

def main():
    N,K = map(int,input().split())
    A = Matrix([list(map(int,input().split())) for _ in range(N)])
    B = A.pow(K,MOD)
    ans = sum(sum(B[i])%MOD for i in range(N))%MOD
    print(ans)
if __name__ == '__main__':
    main()
    
