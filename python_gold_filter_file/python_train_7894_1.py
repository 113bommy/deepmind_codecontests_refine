#encoding: utf-8

def main():
    N,M=map(int,input().split())
    if(abs(N-M)>=2):
        print(0)
        return

    ret=1
    mod=10**9+7
    for i in range(1,N+1):
        ret*=i
        ret%=mod
    for i in range(1,M+1):
        ret*=i
        ret %= mod
    if(N==M):
        r=2
    else:
        r=1
    print((ret*r)%mod)


if __name__ == '__main__':
    main()