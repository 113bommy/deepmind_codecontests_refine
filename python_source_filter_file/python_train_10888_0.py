# coding: utf-8

n, m, k = map(int, input().split())
holes = set(map(int, input().split()))

moves = (
    map(int, input().split()) for _ in range(k)
)

ball = 1

for a, b in moves:
    if ball in holes:
        pass

    if a == ball:
        ball = b
    if b == ball:
        ball = a

print(ball)
