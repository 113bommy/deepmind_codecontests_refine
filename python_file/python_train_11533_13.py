from collections import deque


def main():
    H, W = map(int, input().split())
    Ch, Cw = map(int, input().split())
    Dh, Dw = map(int, input().split())
    S = [input() for _ in range(H)]

    Q = deque([[Ch - 1, Cw - 1, 0]])  # 座標とワープ回数

    cost = [[-1 for _ in range(W)] for _ in range(H)]  # ワープ回数を記録

    while Q:
        r, c, cnt = Q.popleft()

        if cost[r][c] != -1:  # 訪れたことがある
            continue

        cost[r][c] = cnt

        for dr in range(-2, 3):
            for dc in range(-2, 3):
                nr = r + dr
                nc = c + dc

                if 0 <= nr < H and 0 <= nc < W and S[nr][nc] == ".":
                    if abs(dr) + abs(dc) == 1:  # 上下左右
                        Q.appendleft([nr, nc, cnt])
                    elif abs(dr) + abs(dc) >= 2:  # ワープ
                        Q.append([nr, nc, cnt + 1])

    print(cost[Dh - 1][Dw - 1])


if __name__ == "__main__":
    main()
