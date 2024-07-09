import sys
input = sys.stdin.buffer.readline

def main():
    N,x = map(int,input().split())
    a = list(map(int,input().split()))
    b = a.copy()
    
    ans = 10**15
    for i in range(N):
        time = i*x+sum(b)
        ans = min(ans,time)
        for now in range(N):
            b[now] = min(b[now],a[(now-i-1+N)%N])

    print(ans)

if __name__ == "__main__":
    main()
    
