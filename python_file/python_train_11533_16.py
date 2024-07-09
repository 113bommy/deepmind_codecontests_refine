from collections import deque


def main():
    h, w = map(int, input().split())
    cs = list(map(int, input().split()))
    ds = list(map(int, input().split()))
    S = [[s for s in input()] for _ in range(h)]

    curq = deque()
    nexq = deque([(cs[0] - 1, cs[1] - 1)])
    l = 0
    while len(nexq) > 0:
        curq, nexq = nexq, deque()
        while len(curq) > 0:
            y, x = curq.popleft()
            if S[y][x] != ".":
                continue

            S[y][x] = l
            for dy in range(-2, 3):
                for dx in range(-2, 3):
                    if 0 <= y + dy < h and 0 <= x + dx < w and S[y + dy][x + dx] == ".":
                        if abs(dx) + abs(dy) < 2:
                            curq.append((y + dy, x + dx))
                        else:
                            nexq.append((y + dy, x + dx))
        l += 1

    ans = S[ds[0] - 1][ds[1] - 1]
    print(ans if ans != "." else -1)


if __name__ == '__main__':
    main()
