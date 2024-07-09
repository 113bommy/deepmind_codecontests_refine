import sys
input = sys.stdin.readline
sys.setrecursionlimit(pow(10, 6))
from heapq import heappop, heappush

def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    hq = []
    for i, _b in enumerate(b):
        heappush(hq, (-_b, i))

    ans = 0
    while len(hq) != 0:
        q = heappop(hq)
        if -q[0] == a[q[1]]:
            # 同じなら何もする必要はない
            continue
        elif -q[0] < a[q[1]]:
            # 増やすことは出来ないので、小さいなら構築不可
            ans = -1
            break

        ac = b[(q[1] - 1) % n] + b[(q[1] + 1) % n]
        if (b[q[1]] - a[q[1]]) // ac == 0:
            # 一致しておらず、さらに減らせないので構築不可
            ans = -1
            break
        else:
            # できる限り減らす
            tmp = (b[q[1]] - a[q[1]]) // ac
            b[q[1]] -= ac * tmp
            ans += tmp
            heappush(hq, (-b[q[1]], q[1]))
    
    print(ans)

if __name__ == '__main__':
    main()
