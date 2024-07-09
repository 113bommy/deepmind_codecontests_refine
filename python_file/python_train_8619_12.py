import sys, heapq
input = sys.stdin.buffer.readline # 入出力高速化

def main():
    N, Q = map(int, input().split())
    tl = [] # イベントタイムライン
    for _ in range(N):
        S, T, X = map(int, input().split())
        tl.append((S-X, 1, X)) # insert
        tl.append((T-X, 0, X)) # erase
    for _ in range(Q):
        D = int(input())
        tl.append((D, 2, 0)) # min
    tl.sort()
    working = list() # 工事中
    todelete = list() # 削除用
    for t, c, x in tl:
        if c == 0: # erase
            heapq.heappush(todelete, x)
        elif c == 1: # insert
            heapq.heappush(working, x)
        else: # min
            while todelete and todelete[0] == working[0]:
                heapq.heappop(todelete)
                heapq.heappop(working)
            print(-1 if not working else working[0])
    return
    
if __name__ == "__main__":
    main()
