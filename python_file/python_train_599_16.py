
MOD = 998244353
def resolve():
    # 多項式 解
    N, S = map(int, input().split())
    A = list(map(int, input().split()))

    q = [0]*(S+1)
    ans = 0
    for i in range(N):
        q[0] += 1
        q2 = [0]*(S+1)
        for j in range(S+1):
            # q *= (1 + x^A[i])
            q2[j] += q[j]
            if j + A[i] <= S:
                q2[j + A[i]] += q[j]
                q2[j + A[i]] %= MOD
        q = q2
        ans += q[S]
        ans %= MOD
    print(ans)


if __name__ == "__main__":
    resolve()
