import sys
from collections import deque
import heapq

def solve():
    input = sys.stdin.readline
    N, M, P = map(int, input().split())
    graph = [None for i in range(M)]
    for i in range(M):
        a, b, c = map(int, input().split())
        graph[i] = (a - 1, b - 1, P - c)

    gain = [10 ** 20 for i in range(N)]
    gain[0] = 0
    
    for i in range(N):
        update = False
        for efrom, eto, ecost in graph:
            if gain[efrom] < 10 ** 20 and gain[eto] > gain[efrom] + ecost:
                gain[eto] = gain[efrom] + ecost
                update = True
        if not update:
            print(max(-gain[N-1], 0))
            break
    else:
        possible_min = gain[N-1]
        for i in range(N):
            for efrom, eto, ecost in graph:
                if gain[efrom] < 10 ** 20 and gain[eto] > gain[efrom] + ecost:
                    gain[eto] = gain[efrom] + ecost

        if gain[N-1] == possible_min: print(max(-gain[N-1], 0))
        else: print(-1)

    return 0

if __name__ == "__main__":
    solve()