import sys
from copy import deepcopy

def canMake(k, Nums):#Numsにある数でkを作れるか
    L = len(Nums)
    index = 0
    bit = []
    for i in reversed(range(60)):
        flag = 0
        for j in range(index, L):
            if Nums[j] & (1 << i) == (1 << i):
                flag = 1
                Nums[index], Nums[j] = Nums[j], Nums[index]
                bit.append(i)
                break
        if flag == 1:
            for j in range(L):
                if Nums[j] & (1 << i) == (1 << i) and index != j: Nums[j] ^= Nums[index]
        if flag == 1: index += 1
    ans = 0
    for i in range(60):
        if k & (1 << i) == (1 << i):
            if i in bit: ans ^= Nums[bit.index(i)]
    if ans == k: return True
    else: return False


def solve():
    input = sys.stdin.readline
    T = int(input())
    Ans = [0] * T
    for t in range(T):
        N = int(input())
        A = [int(a) for a in input().split()]
        S = input().strip("\n")
        used = []
        for i in reversed(range(N)):
            if S[i] == "0":
                used.append(A[i])
            else:
                compare = deepcopy(used)
                if not canMake(A[i], compare):
                    Ans[t] = 1
                    break
    
    print(*Ans, sep="\n")

    return 0

if __name__ == "__main__":
    solve()
