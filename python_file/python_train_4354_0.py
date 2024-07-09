import sys
input = sys.stdin.buffer.readline

def main():
    N = int(input())
    a = list(map(int,input().split()))
    dp = [[-1 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        dp[i][i] = a[i]
    
    for i in range(N-1,-1,-1):
        for j in range(i,N):
            if dp[i][j] != -1:
                continue
            dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1])
            
    print(dp[0][-1])
   
if __name__ == "__main__":
    main()
