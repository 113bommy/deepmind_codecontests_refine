N = int(input())

ga, sa, ba = list(map(int, input().split()))
gb, sb, bb = list(map(int, input().split()))

# case
# すべて a > b
# すべて b < a
# 2個  a > b
# 1個  a > b

# weight:ga price:gb どんぐり weight:1 price:1


vmax = 0
for g in range(0,N + 1, ga):
    for s in range(0,N + 1 - g, sa):
        v = (g // ga) * gb + (s // sa) * sb
        amari = N - g - s
        if amari < 0:
            break
        if ba < bb:
            v += amari // ba * bb
            amari %= ba
        v += amari

        vmax = max(vmax, v)

D = vmax
vmax = D

if ba < bb:
    tmp = sa,sb
    sa,sb = ba,bb
    ba,bb = tmp

for g in range(0,D + 1, gb):
    if ga < gb and g > 0:
        break
    for s in range(0, D + 1 - g, sb):
        if sa < sb and s > 0:
            break
        v = (g // gb) * ga + (s // sb) * sa
        amari = D - g - s
        if amari < 0:
            break
        if ba > bb:
            v += amari // bb * ba
            amari %= bb
        v += amari

        vmax = max(vmax, v)

print(vmax)
