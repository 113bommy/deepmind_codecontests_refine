S = input()
T = input()


def solve(S, T):
    for t in set(T):
        if t not in set(S):
            return -1

    S_double = S+S
    len_s = len(S)
    ans = -1
    for t in T:
        ans += S_double[(ans+1) % len_s:].index(t) + 1
    return ans + 1


print(solve(S, T))
