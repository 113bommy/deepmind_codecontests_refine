import sys
sys.setrecursionlimit(10000000)
MOD = 998244353
INF = 10 ** 15

def main():
    N,S = map(int,input().split())
    A = list(map(int,input().split()))

    before = [0] * (1 + S)
    before[0] = 1
    ans = 0
    for a in A:
        now = [0] * (1 + S)
        for i in range(S + 1):
            now[i] += before[i]
            if i + a <= S:
                now[i + a] += before[i]
                now[i + a] %= MOD
        now[0] += 1
        ans += now[S]
        ans %= MOD
        before = now
    print(ans)
if __name__ == '__main__':
    main()