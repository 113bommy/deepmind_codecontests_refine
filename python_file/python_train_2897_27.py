import sys
input = sys.stdin.readline

def main():
    N = int(input())
    state = [list(input()) for _ in range(N)]

    ans = 0
    for i in range(N):
        ok = True
        for x in range(N):
            for y in range(N):
                if state[(x+i)%N][y] != state[(i+y)%N][x]:
                    ok = False
                    break
        if ok:
            ans += N
    print(ans)

if __name__ == "__main__":
    main()