from collections import deque


def main():
    H, W = map(int, input().split())
    Ch, Cw = map(int, input().split())
    Dh, Dw = map(int, input().split())
    S = [list(input()) for _ in range(H)]
    d = [[-1 for _ in range(W)] for _ in range(H)]

    q = deque([])
    q.appendleft((0, Ch - 1, Cw - 1))

    while len(q):
        worp_count, x, y = q.popleft()

        if d[x][y] != -1:
            continue
        d[x][y] = worp_count

        for i, j in ((a, b) for a in range(-2, 3) for b in range(-2, 3)):
            nx = x + i
            ny = y + j
            if 0 <= nx < H and 0 <= ny < W and S[nx][ny] == '.':
                if i == 0 and j == 0:
                    continue
                elif abs(i) + abs(j) == 1:
                    q.appendleft((worp_count, nx, ny))
                else:
                    q.append((worp_count + 1, nx, ny))

    print(d[Dh - 1][Dw - 1])


if __name__ == "__main__":
    main()
