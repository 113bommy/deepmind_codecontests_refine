import sys
from operator import itemgetter
from collections import deque, Counter
from itertools import permutations, combinations
from heapq import heapify, heappop, heappush
from bisect import bisect, bisect_left

def search(n, x, m, K, D):
    ini = x % m
    modD = [D[i] % m for i in range(K)]
    roop , rem = (n - 1) // K, (n - 1) % K
    last = ini
    equal = 0
    for i in range(K):
        if i < rem and rem > 0:
            if modD[i] == 0: equal += roop + 1
            else: last += (roop + 1) * modD[i]
        else:
            if modD[i] == 0: equal += roop
            else: last += roop * modD[i]
    up = (last // m) - (ini // m)
    return n - 1 - equal - up

def solve():
    input = sys.stdin.readline
    K, Q = map(int, input().split())
    D = [int(d) for d in input().split()]
    Ans = []
    for _ in range(Q):
        n, x, m = map(int, input().split())
        Ans.append(search(n, x, m, K, D))

    for i, a in enumerate(Ans): print(a)

    return 0

if __name__ == "__main__":
    solve()